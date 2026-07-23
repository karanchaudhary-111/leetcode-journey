class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;

        if(!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();

            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;

            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                
                if(level % 2 == 0){
                    
                    if(temp -> val % 2 == 0)return false;

                    if(prev >= temp -> val) return false;

                }else{

                    if(temp -> val % 2 != 0)return false;

                    if(prev <= temp -> val) return false;

                }

                prev = temp -> val;
                
                if(temp -> left != NULL){
                    q.push(temp -> left);
                }

                if(temp -> right != NULL){
                    q.push(temp -> right);
                }
            }
            level++;
        }

        return true;  
    }
};