class Solution {
public:

    void solve(TreeNode* leftNode,TreeNode* rightNode,int lvl){
        if(!leftNode) return;
        if(lvl % 2 != 0){
            swap(leftNode->val, rightNode->val);
        }
        solve(leftNode->left, rightNode->right, lvl+1);
        solve(rightNode->left, leftNode->right, lvl+1);
        return ;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left,root->right,1);
        return root;
    }
};