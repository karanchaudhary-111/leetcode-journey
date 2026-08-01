class Solution {
public:
    int dp[21][21];
    int solve(int i, int j, vector<int>& nums) {
        if (i == j) return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeLeft = nums[i] - solve(i + 1, j, nums);
        int takeRight = nums[j] - solve(i, j - 1, nums);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));

        return solve(0, n - 1, nums) >= 0;
    }
};