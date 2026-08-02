class Solution {
public:

    void solve(TreeNode* root, int low, int high, int &ansSum){
        if(!root) return ;

        if(root -> val >= low && root -> val <= high){
            ansSum += root -> val;
        }

        if(root -> val > low){
            solve(root -> left, low, high, ansSum);
        }

        if(root -> val < high){
            solve(root -> right, low, high, ansSum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {

        int ans = 0;
        solve(root, low, high, ans);

        return ans;
    }
};