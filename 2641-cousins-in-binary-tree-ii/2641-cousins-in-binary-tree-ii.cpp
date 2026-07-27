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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int levelSum = root -> val;

        while(!q.empty()){
            int n = q.size();
            int nextSum = 0;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                curr -> val = levelSum - curr -> val;

                int siblingSum = curr -> left != NULL ? curr -> left -> val: 0;
                siblingSum += curr -> right != NULL ? curr -> right -> val : 0;

                nextSum += siblingSum;

                if(curr -> left){
                    curr -> left -> val = siblingSum;
                    q.push(curr -> left);
                } 

                if(curr -> right){
                    curr -> right -> val = siblingSum;
                    q.push(curr -> right);
                }
            }
            levelSum = nextSum;
        }
        return root;
    }
};