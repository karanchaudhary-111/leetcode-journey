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

        int front = right + 1;
        int back = n - left;
        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};