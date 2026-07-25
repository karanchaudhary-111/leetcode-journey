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

    bool findPath(TreeNode* root, int target, string& path){
        if(root == NULL) return false;

        if(root -> val == target) return true;

        path.push_back('L');
        if(findPath(root -> left, target, path) == true){
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if(findPath(root -> right, target, path) == true){
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        string source = "";
        string destination = "";

        findPath(root, startValue, source);
        findPath(root, destValue, destination);

        string result = "";

        int l = 0;

        while(l < source.size() && l < destination.size() && source[l] == destination[l]){
            l++;
        }

        for(int i = 0; i < source.size() - l; i++){
            result.push_back('U');
        }
        
        for(int i = l; i < destination.size(); i++){
            result.push_back(destination[i]);
        }

        return result;
    }
};