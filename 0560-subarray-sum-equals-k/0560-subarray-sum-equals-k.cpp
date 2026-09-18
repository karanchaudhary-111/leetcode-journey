class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> mp;
        int cnt = 0;
        int prefixSum = 0;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];
            int remove =  prefixSum - k;
            cnt += mp[remove];
            mp[prefixSum] += 1;
        }

        return cnt;

    }
};