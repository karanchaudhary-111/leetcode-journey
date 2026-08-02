class Solution {
public:

    void solve(TreeNode* root, vector<int> &vec){
        if(!root) return ;

        solve(root -> left, vec);

        vec.push_back(root -> val);

        solve(root -> right, vec);

    }

    int getMinimumDifference(TreeNode* root) {
        
        vector<int> store;

        solve(root, store);

        int i = 1;
        int ans = INT_MAX;

        while(i < store.size()){
            int sub = abs(store[i-1] - store[i]);
            ans = min(sub, ans);
            i++;
        }

        return ans;
    }
};