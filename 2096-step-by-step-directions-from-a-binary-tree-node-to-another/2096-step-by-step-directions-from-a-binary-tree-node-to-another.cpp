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

    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        
        if(root == NULL || root -> val == p || root -> val == q) return root;

        TreeNode* leftN = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root -> right, p, q);

        if(leftN && rightN){
            return root;
        }

        return leftN ? leftN : rightN;
    }

    bool findPath(TreeNode* lca, int target, string& path){
        if(lca == NULL) return false;

        if(lca -> val == target) return true;

        path.push_back('L');
        if(findPath(lca -> left, target, path) == true){
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if(findPath(lca -> right, target, path) == true){
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root, startValue, destValue);

        string source = "";
        string destination = "";

        findPath(lca, startValue, source);
        findPath(lca, destValue, destination);

        string result = "";

        for(int i  = 0; i < source.size(); i++){
            result.push_back('U');
        }

        result += destination;

        return result;
    }
};