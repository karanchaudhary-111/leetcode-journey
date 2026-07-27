class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int n = q.size(); 
            vector<int> tempResult(n);
            int i = 0;

            while(i < n){
                TreeNode* curr = q.front();
                q.pop();

                int index = leftToRight ? i : (n - 1 - i);
                tempResult[index] = curr->val;

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);

                i++;

            }
            leftToRight = !leftToRight;
            ans.push_back(tempResult);
        }

        return ans;
    }
};