class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        int idx = 0;
        vector<int> temp;

        k = k % n;

        for(int i = 0; i < n; i++){
            if(i < n-k){
                temp.push_back(nums[i]);
            }else{
                nums[idx++] = nums[i];
            }
        }

        for(auto& it: temp){
            nums[idx++] = it;
        }
    }
};