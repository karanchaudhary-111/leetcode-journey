class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int solve = 0;
        int n = nums.size();

        for(int x : nums){
            solve =  solve ^ x;
        }

        if(solve != 0) return n;

        for(int x : nums){
            if(x != 0) return n-1;
        }

        return 0;
    }
};