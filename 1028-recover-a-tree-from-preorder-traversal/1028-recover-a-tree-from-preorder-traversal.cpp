class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0;
        TreeNode* root = nullptr;

        while (i < traversal.size()) {
            int depth = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }

            int val = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            if (depth == 0) {
                root = node;
            } else {
                while (st.size() > depth)
                    st.pop();

                TreeNode* parent = st.top();

                if (!parent->left)
                    parent->left = node;
                else
                    parent->right = node;
            }

            st.push(node);
        }

        return root;
    }
};