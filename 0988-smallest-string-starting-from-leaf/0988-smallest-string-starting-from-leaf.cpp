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

    void solve(TreeNode* root, string temp, string &result){
        if(!root) return ;

        temp = char(root -> val + 'a') + temp;

        if(root -> left == NULL && root -> right == NULL){
            if(result == "" || result > temp){
                result = temp;
            }
        }

        solve(root -> left, temp, result);
        solve(root -> right, temp, result);
    }

    string smallestFromLeaf(TreeNode* root) {
        string temp = "";
        string result = "";

        solve(root, temp, result);

        return result;
    }
};