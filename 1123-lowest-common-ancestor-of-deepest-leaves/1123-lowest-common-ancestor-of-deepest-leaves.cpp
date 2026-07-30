class Solution {
public:

    int maxDepth = 0;

    TreeNode* lowestCommonAncestor(TreeNode* root, int maxDepth, int depth) {
        
        if(root == NULL) return root;

        if(depth == maxDepth){
            return root;
        }

        TreeNode* leftN = lowestCommonAncestor(root -> left, maxDepth, depth + 1);
        TreeNode* rightN = lowestCommonAncestor(root -> right, maxDepth, depth + 1);

        if(leftN != NULL && rightN != NULL){
            return root;
        }

        return leftN ? leftN : rightN;
    }

    void getDepth(TreeNode* root, int depth, unordered_map<TreeNode*, int> mp){
        if(!root) return ;

        mp[root] = depth;
        maxDepth = max(maxDepth, depth);

        getDepth(root -> left, depth+1, mp);
        getDepth(root -> right, depth+1, mp);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;

        getDepth(root, 0, mp);

        return lowestCommonAncestor(root, maxDepth, 0);

        
    }
};