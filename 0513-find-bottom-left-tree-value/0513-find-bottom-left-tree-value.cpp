/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    unordered_map<int, int> mp;

    int height(TreeNode* root){
        if(!root) return 0;

        int l = height(root -> left);
        int r = height(root -> right);

        return max(l, r) + 1;
    }

    void solve(TreeNode* root, int level){

        if(!root) return ;

        if(root -> left == NULL && root -> right == NULL){
            if(mp.find(level) == mp.end()){
                mp[level] = root -> val;
                return;
            }
        }
        solve(root -> left, level+1);
        solve(root -> right, level+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        
        if(root == NULL)return 0;

        int depth = height(root);
        solve(root, 1);

        int ans = mp[depth];

        return ans;
     }
};