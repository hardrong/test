#include"BinaryTree.h"

BTNode* BuyBTNode(BTDataType x) 
{
	BTNode * buy = (BTNode *)malloc(sizeof(BTNode));
	buy->_data = x;
	buy->_left = NULL;
	buy->_right = NULL;

	return buy;
}
BTNode* CreateBTree(BTDataType* a, int* pIndex, BTDataType invalid)
{
	
	if(a[(*pIndex)] != '#')
	{
		BTNode * root = BuyBTNode(*pIndex);
		root->_data = a[(*pIndex)];
		++(*pIndex);
		root->_left = CreateBTree(a,pIndex,invalid);
		++(*pIndex);
		root->_right = CreateBTree(a,pIndex,invalid);

		return root;

	}
	else
		return NULL;
          
}
void BinaryTreeDestory(BTNode* root)
{
	if(root->_left == NULL && root->_right == NULL)
		{
			free(root);
			root = NULL;
			return;
	    }
	else
	{
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
	}

	      
}
size_t BTreeSize(BTNode* root)
{

	if(root == NULL)
		return 0;

	return BTreeSize(root->_left)
		+ BTreeSize(root->_right)+ 1;
}
size_t BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL
		&& root->_right == NULL)
		return 1;

	return BTreeLeafSize(root->_left)
		+ BTreeLeafSize(root->_right);

}
size_t BTreeKLevelSize(BTNode* root, size_t k)
{
	//既然要K层的结点，那么先要走到K层，给K每次减一，它就到K层了
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTreeKLevelSize(root->_left, k-1)
		+ BTreeKLevelSize(root->_right, k-1);
}
void BTreePrevOrder(BTNode* root)
{
	if( root == NULL)
		return ;
	printf("%d\n",root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);


}
size_t BTreeDepth(BTNode* root,size_t left,size_t right)
{
	//如果去求深度，第一种考虑为去求他们的权值，也就是路径最长的
	//但是太复杂，二叉树的思想是递归，所以我们应该想到大事化小，小事化无
	//先分析根节点，当有左子树，没有子树时，那么应该是左子树的深度加一，
	//当同时有左子树时，应该是深度大的加一
	if(root == NULL)
		return 0;
	
      left= BTreeDepth(root->_left,left,right);
	 right= BTreeDepth(root->_right,left,right);

	return (left > right)?left+1:right+1 ;

}
void TestBinaryTree() 
{ 
	int a[] = {1, 2, 3, '#', '#',4,7,'#','#', '#', 5, 6,'#' ,'#' ,'#' }; 
 int sz = 0;
  size_t Depth = 0;
int *index = &sz ; 

BTNode* tree = CreateBTree(a, index, '#'); 
  Depth =   BTreeDepth(tree,0,0);
  printf("%d\n",Depth);
   BTreePrevOrder(tree);
   
}