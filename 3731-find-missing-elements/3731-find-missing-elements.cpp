class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n =  nums.size();

        vector<int> ans;

        int maxi = -1;
        int mini = 101;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        int m = maxi - mini + 1;

        vector<int> arr(m, -1);

        for(int i = 0; i < n; i++){
            arr[nums[i] - mini] = nums[i] - mini;
        }

        for(int i = 0; i < m; i++){
            if(arr[i] == -1){
                ans.push_back(i + mini);
            }
        }

        return ans;
    }
};