class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();

        unordered_set<int> temp;
        unordered_set<int> res;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                temp.insert(nums[i] ^ nums[j]);
            }
        }

        for(int pair : temp){
            for(int& x: nums){
                res.insert(pair ^ x);
            }
        }

        return res.size();
    }
};