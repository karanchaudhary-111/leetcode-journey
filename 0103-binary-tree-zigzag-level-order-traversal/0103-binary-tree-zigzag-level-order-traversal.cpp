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
            vector<int> tempResult;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                tempResult.push_back(curr -> val);

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);

            }
            if(leftToRight == false){
                reverse(tempResult.begin(), tempResult.end());
            }
            leftToRight = !leftToRight;
            ans.push_back(tempResult);
        }

        return ans;
    }
};