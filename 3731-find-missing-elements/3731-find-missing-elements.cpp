class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n =  nums.size();

        vector<int> ans;

        int maxi = -1;
        int mini = 101;

        set<int> st;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
            st.insert(nums[i]);
        }

        for(int i = mini+1; i < maxi; i++){
            if(st.count(i) == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};