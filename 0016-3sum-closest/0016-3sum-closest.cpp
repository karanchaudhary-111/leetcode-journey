class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();

        sort(begin(nums), end(nums));
        int ans = 100000;

        for(int i = 0; i < n-1; i++){
            int a = nums[i];
            int left  = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(abs(target - sum) < abs(target - ans)){
                    ans = sum;
                }

                if(sum > target){
                    right--;
                }else{
                    left++;
                }
            }
        }

        return ans;
    }
};