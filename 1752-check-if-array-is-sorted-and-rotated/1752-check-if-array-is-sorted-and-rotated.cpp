class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int minIdx  = 0;

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                minIdx = i+1;
            }
        }

        for(int i = 0; i < n-1; i++){
            if(nums[(i+minIdx) % n] > nums[(i + minIdx + 1) % n]){
                return false;
            }
        }

        return true;
    }
};