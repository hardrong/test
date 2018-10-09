class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
     if(pRoot == NULL)
         return true;
      
            return  Symmetrical(pRoot->left,pRoot->right);
    }
    bool Symmetrical(TreeNode *pleft,TreeNode *pright)
    {
        bool result = false;
        if(pleft == NULL && pright == NULL)
            return true;
            
        if(pleft &&pright)
        {
        if(pleft->val == pright->val)
        {
       result = Symmetrical(pleft->right,pright->left)&&
                 Symmetrical(pleft->left,pright->right);
        }
        }
       
        return result;
    }