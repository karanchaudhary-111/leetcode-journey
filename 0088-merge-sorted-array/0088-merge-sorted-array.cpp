class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int s = m + n - 1;

        int i = m - 1;
        int j =  n - 1;

        if(m == 0){
            for(int i = 0; i < n; i++){
                nums1[i] = nums2[i];
            }
            return;
        }

        while(i >= 0 && j >= 0){
            if(nums1[i] < nums2[j]){
                nums1[s--] = nums2[j];
                j--;
            }else{
                nums1[s--] = nums1[i];
                i--;
            }
        }

        while(j >= 0){
            nums1[s--] =  nums2[j--];
        }
        
    }
};