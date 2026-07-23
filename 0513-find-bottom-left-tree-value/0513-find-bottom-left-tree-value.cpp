class Solution {
public:

    void solve(TreeNode* root, int depth, int& maxDepth, int &result){

        if(!root) return ;

        if(depth > maxDepth){
            maxDepth =  depth;
            result = root -> val;
        }
        solve(root -> left, depth+1, maxDepth, result);
        solve(root -> right, depth+1, maxDepth, result);
    }

    int findBottomLeftValue(TreeNode* root) {
        
        if(root == NULL)return 0;

        int result = INT_MIN;
        int maxDepth =  -1;
        solve(root, 1, maxDepth, result);

        return result;
     }
};