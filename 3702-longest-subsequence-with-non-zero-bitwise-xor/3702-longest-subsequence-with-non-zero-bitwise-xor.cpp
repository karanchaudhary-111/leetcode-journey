class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int solve = 0;
        int n = nums.size();
        bool nonZero = false;

        for(int x : nums){
            solve =  solve ^ x;
            if(solve != 0){
                nonZero = true;
            }
        }

        if(solve != 0) return n;

        return nonZero ? n - 1 : 0;
    }
};