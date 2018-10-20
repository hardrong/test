/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

         vector<vector<int> >array;
        vector<int>arr;
       if(root == NULL)
        return array;
        if(expectNumber <root->val)
        {
            return array;
        }
      isfindpath(root,expectNumber,arr,array);
        
        return array;

            }
   void isfindpath(TreeNode *root,int number,vector<int>&arr,vector<vector<int> >&array)
    {
       if(root != NULL)
       {
       arr.push_back(root->val);
        if(number == root->val && !root->left &&!root->right)
        {
            array.push_back(arr);
        }
        if(number < 0)
        {
            return;
        }
        isfindpath(root->left,number-(root->val),arr,array);
        isfindpath(root->right,number-(root->val),arr,array);
        arr.pop_back();
       }
        return ;
    }

};