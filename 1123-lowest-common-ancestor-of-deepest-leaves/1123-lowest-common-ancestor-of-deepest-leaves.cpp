class Solution {
public:

    pair<int, TreeNode*> solve(TreeNode* root){
        if(!root) return {0, NULL};

        pair<int, TreeNode*> l = solve(root -> left);
        pair<int, TreeNode*> r = solve(root -> right);

        if(l.first == r.first){
            return {l.first+1, root};
        }

        if(l.first > r.first){
            return {l.first+1, l.second};
        }else{
            return {r.first+1, r.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};