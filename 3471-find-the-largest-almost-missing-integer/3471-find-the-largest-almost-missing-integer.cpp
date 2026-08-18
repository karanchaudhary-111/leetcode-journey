class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = -1;

        unordered_map<int,int> freq;

        for(int i : nums){
            freq[i]++;
        }

        if(n == k){
            for(int i =  0;  i < n; i++){
                if(maxEl < nums[i]){
                    maxEl = nums[i];
                }
            }
        }else if(k == 1){
            for(int i = 0; i < n; i++){
                if(freq[nums[i]] == 1){
                    maxEl = max(maxEl, nums[i]);
                }
            }
        }else{
            if(freq[nums[0]] == 1){
                maxEl = max(maxEl, nums[0]);
            }

            if(freq[nums[n-1]] == 1){
                maxEl = max(maxEl, nums[n-1]);
            }
        }

        return maxEl;
    }
};