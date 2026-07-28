class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> temp;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr);

                if(curr -> left){
                    q.push(curr -> left);
                }

                if(curr -> right){
                    q.push(curr -> right);
                }
            }
            int l = 0, r = temp.size() -1;
            if(level % 2 == 1){
                while(l < r){
                    int x = temp[l] -> val;
                    temp[l] -> val = temp[r] -> val;
                    temp[r] -> val = x;

                    l++; r--;
                }
            }
            level++;
        }
        return root;
    }
};