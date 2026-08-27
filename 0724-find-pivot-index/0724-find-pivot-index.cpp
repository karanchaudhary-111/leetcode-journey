class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();

        int leftSum  = 0;
        int rightSum = 0;

        for(int i = 0; i < n; i++){
            rightSum += nums[i];
        }

        for(int i = 0; i < n; i++){
            rightSum -= nums[i];

            if(i-1 >= 0){
                leftSum += nums[i-1];
            }

            if(leftSum == rightSum){
                return i;
            }
        }

        return -1;
    }
};