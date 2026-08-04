class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        sort(begin(nums), end(nums));

        int i = 1;

        while( i < n){
            int j = 1;
            while(nums[i] != nums[i-1] + j){
                ans.push_back(nums[i-1] + j);
                j++;
            }
            i++;
        }

        return ans;
    }
};