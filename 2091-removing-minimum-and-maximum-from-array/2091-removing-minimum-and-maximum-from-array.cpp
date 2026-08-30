class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int miniIdx = 0;
        int maxiIdx = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < nums[miniIdx]) {
                miniIdx = i;
            }

            if(nums[i] > nums[maxiIdx]) {
                maxiIdx = i;
            }
        }

        int left = min(miniIdx, maxiIdx);
        int right = max(miniIdx, maxiIdx);


        return min({left + right - left + 1, n-1-right+left+2, right - left + n-1-right+1});
    }
};