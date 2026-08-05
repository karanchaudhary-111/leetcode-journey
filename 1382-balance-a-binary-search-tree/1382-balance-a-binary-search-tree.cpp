class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sortedArrayToBST(0, sorted_array.size() - 1);
    }

private:
    TreeNode* sortedArrayToBST(int start, int end)
    {
        if (start > end)
            return nullptr;
            
        int mid = (start + end) / 2;

        TreeNode* root = sorted_array[mid];

        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);

        return root;
    }

    void inorder(TreeNode* node)
    {
        if (!node)
            return;

        inorder(node->left);

        sorted_array.push_back(node);

        inorder(node->right);
    }

    vector<TreeNode*> sorted_array;
};