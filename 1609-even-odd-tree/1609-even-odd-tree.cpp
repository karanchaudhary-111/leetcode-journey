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

    vector<int> levelPrev;

    bool solve(TreeNode* root, int level){

        if(!root) return true;

        if(level % 2 == root -> val % 2) return false;

        if(level >= levelPrev.size()){
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0){

            if(level % 2 == 0 && levelPrev[level] >= root -> val)return false;

            if(level % 2 != 0 && levelPrev[level] <= root -> val) return false;
        }

        levelPrev[level] = root ->val;

        bool l = solve(root -> left, level + 1);
        bool r = solve(root -> right, level + 1);

        return l && r;
    }
    bool isEvenOddTree(TreeNode* root) {
        return solve(root, 0);
    }
};