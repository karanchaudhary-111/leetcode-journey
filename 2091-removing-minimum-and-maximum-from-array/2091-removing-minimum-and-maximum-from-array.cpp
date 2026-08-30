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

        int front = max(miniIdx, maxiIdx)+1;
        int back = n - min(miniIdx, maxiIdx);
        int frontBack = (min(miniIdx, maxiIdx)+1) + (n-max(miniIdx, maxiIdx));
        int minDeletion = min({front, back, frontBack});
        return minDeletion;
    }
};