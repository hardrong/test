class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
        
              vector<vector<int> >array;
            if(pRoot == NULL)
                return array;
          
            
            queue<TreeNode *>q;
            q.push(pRoot);
          
            while(!q.empty())
            {
                int i = 0;
                vector<int>a;
                int hight = q.size();
                while(i<hight)
                {
                a.push_back(q.front()->val);
                if(q.front()->left!=NULL)
                    q.push(q.front()->left);
                if(q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
                i++;
                }
                array.push_back(a);
            }
            return array;
        }
    
};