class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> vec(101, 0);

        for(int i = 0; i < n; i++){
            vec[nums[i]]++;
        }

        int i = 1;

        while( k*i <= 100 &&  vec[k*i] != 0){
            i++;
        }

        return k*i;
    }
};