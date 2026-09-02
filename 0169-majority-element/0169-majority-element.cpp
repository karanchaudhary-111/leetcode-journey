class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =  nums.size();

        int candidate = 0;
        int voting = 0;

        for(auto& it: nums){
            if(voting == 0){
                candidate = it;
            }

            if(candidate == it){
                voting++;
            }else{
                voting--;
            }
        }

        return candidate;
    }
};