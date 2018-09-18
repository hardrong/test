#include"btstree.h"


BSTreeNode* BuyBSTreeNode(DataType x)
{
	BSTreeNode * buy = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	buy->_left = NULL;
	buy->_right = NULL;
	buy->_data = x;
	return buy;
}
void CreateBStree(BSTreeNode **tree,DataType x)
{
	BSTreeNode * cur = NULL;
	BSTreeNode * parent = NULL;
	assert(tree);
	if(*tree == NULL)
	{
		*tree = BuyBSTreeNode(x);
		return ;
	}
		cur = *tree;
		while(cur )
		{
		
		if((cur)->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if((cur)->_data < x)
		{
				parent = cur;
			cur = cur->_right;
		}
		else
		{
			printf("插入错误\n");
			return ;
		}
		}
		if(parent->_data > x)
		{
			parent->_left = BuyBSTreeNode(x);
		}
		else
		{
			parent->_right = BuyBSTreeNode(x);
		}

		
	
}
const BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x)
{
	BSTreeNode *cur = NULL;
	BSTreeNode *parent =NULL;
	assert(tree);

	cur = tree;
	while(cur)
	{

		if( cur->_data < x)
		{

			cur = cur->_right;
		}
		else if(cur->_data >x)

		{
			cur = cur->_left;
		}
		else
			return cur;
	}
	return NULL;
}
int BSTreeRemove(BSTreeNode** tree, DataType x)
{
	BSTreeNode * cur =NULL;
	BSTreeNode *parent = NULL;
	assert(tree);
	cur = *tree;
	
	while(cur)
	{

		if( cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else if(cur->_data >x)

		{
			parent = cur;
			cur = cur->_left;
		}

		else
		{
			
			if(cur->_left == NULL)
			{
				if(parent == NULL)
				{
					cur  = cur->_right;
				}
				else
				{
					if (cur == parent->_left)
				    {
						parent->_left = cur->_right;
						
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				
				}
				else if(cur->_right == NULL)
			{
				if (parent == NULL)
				{
					*tree = cur->_left;
				}
				else
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
				{
						parent->_right = cur->_left;
				}
				}
			}
				else
				{
						BSTreeNode* replace = cur->_right;
				while (replace->_left)
				{
					replace = replace->_left;
				}

				cur->_data = replace->_data;

				return BSTreeRemove(&cur->_right, replace->_data);
			}

			free(cur);

			return 1;
		}
	}

}
void BSTreeDestory(BSTreeNode* tree)
{
	if(tree->_left == NULL)
		return;
	if(tree->_right == NULL)
		return;
	if(tree->_left== NULL  && tree->_right == NULL)
	{
		free(tree);
		tree = NULL;
	
	}
	
       BSTreeDestory(tree->_left);
	   BSTreeDestory(tree->_right);

}
int BSTreeInsertR(BSTreeNode** tree, DataType x)
{
	if(*tree)
	{
		*tree = BuyBSTreeNode(x);
		return 1;
	}
	if((*tree)->_data < x)
	{
		BSTreeInsertR(&(*tree)->_right,x);
	}
	else if((*tree)->_data >x)
	{
		
		BSTreeInsertR(&(*tree)->_left,x);
	}
	else
		return 0;
}
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x)
{
	if(tree)
		return NULL;
	if(tree->_data >x )
	{
		 return BSTreeFind(tree->_left,x);
	}
	else if(tree->_data < x)
	{
		 return BSTreeFind(tree->_right,x);
	}
	else
		return tree;

	return NULL;
}
int BSTreeRemoveR(BSTreeNode** tree, DataType x)
{
	if(*tree)
		return NULL;
	//找到了
	// 左为空，右为空，左右都不为空
	if((*tree)->_data == x)
	{
				BSTreeNode* del = *tree;

		if ((*tree)->_left == NULL)
		{
			*tree = (*tree)->_right;

			free(del);
		}
		else if ((*tree)->_right == NULL)
		{
			*tree = (*tree)->_left;

			free(del);
		}
		else
		{
			//可以找到有孩子的最左结点，替换，再递归，把它看成子问题
			BSTreeNode* replace = (*tree)->_right;
			while (replace->_left)
			{
				replace = replace->_left;
			}

			(*tree)->_data = replace->_data;

			return BSTreeRemoveR(&(*tree)->_right, replace->_data);
		}
	
	}
	if((*tree)->_data < x)
	{
		BSTreeRemoveR(&(*tree)->_right,x);
	}
	if((*tree)->_data > x)
	{
		BSTreeRemoveR(&(*tree)->_left,x);
	}
}
void TestBSTree()
{
	int i = 0;
	BSTreeNode* pTree = NULL;
	const BSTreeNode * ret = NULL;
	int a[] = {5,3,4,1,7,8,2,6,0,9};
	for (; i < sizeof(a)/sizeof(int); ++i)
	{	
		CreateBStree(&pTree, a[i]);
		
	}
	BSTreeRemove(&pTree,6);
	ret = BSTreeFind(pTree,6);
	
	BSTreeDestory(pTree);

}
// key 
// key/value
BSTreeNode* BuyBSTreeNode(BSTKeyType key, BSTValueType value)
{
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_key = (BSTKeyType)malloc(strlen(key)+1);
	strcpy(node->_key, key);
	node->_value = value;

	return node;
}

int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value)
{
	BSTreeNode* cur, *parent;
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(key, value);
		return 1;
	}

	cur = *ppTree;
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return 0;
		}
	}

	if (strcmp(parent->_key, key) < 0)
	{
		parent->_right = BuyBSTreeNode(key, value);
	}
	else
	{
		parent->_left = BuyBSTreeNode(key, value);
	}

	return 1;
}

BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key)
{
	BSTreeNode* cur = *ppTree;
	while (cur)
	{
		if (strcmp(cur->_key, key) < 0)
		{
			cur = cur->_right;
		}
		else if (strcmp(cur->_key, key) > 0)
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}

	return NULL;
}

void BSTreeInOrder(BSTreeNode** ppTree)
{
	BSTreeNode* root = *ppTree;
	if (*ppTree == NULL)
	{
		return;
	}

	BSTreeInOrder(&root->_left);
	printf("%s:%d\n", root->_key, root->_value);
	BSTreeInOrder(&root->_right);
}

