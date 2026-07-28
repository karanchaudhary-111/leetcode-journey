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
class FindElements {
public:
    TreeNode* newRoot = new TreeNode(0);
    bool DFS(TreeNode* &root, int x, int target){
        if(!root) return false;

        root -> val = x;
        
        if(root -> val == target){
            return true;
        }

        bool l = DFS(root -> left, 2*x + 1, target);
        bool r = DFS(root -> right, 2*x + 2, target);

        return l || r;

    }
    FindElements(TreeNode* root) {
        newRoot = root;
    }
    
    bool find(int target) {
       return DFS(newRoot, 0, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */