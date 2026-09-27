class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        int n = rowIndex;

        vector<int> ans(n+1);
        long long val = 1;

        for(int r = 0; r <= n; r++){
            ans[r] = val;

            val = (val * (n - r)) / (r + 1);
        }

        return ans;
    }
};