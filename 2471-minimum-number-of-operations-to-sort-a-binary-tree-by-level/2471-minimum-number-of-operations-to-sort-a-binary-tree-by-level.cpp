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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<pair<int, int>> vec;
            for (int i = 0; i < sz; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                vec.push_back({cur->val, i});
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            sort(vec.begin(), vec.end());
            int idx = 0;
            while (idx < vec.size()) {
                if (vec[idx].second == idx) {
                    idx++;
                } else {
                    while (vec[idx].second != idx) {
                        swap(vec[idx], vec[vec[idx].second]);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};