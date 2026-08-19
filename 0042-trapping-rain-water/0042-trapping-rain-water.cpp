class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n-1;
        int rightMax =0;
        int leftMax =0;
        int ans =0;

        while(l<r){
            rightMax = max(rightMax,height[r]);
            leftMax = max(leftMax,height[l]);

            if(rightMax<leftMax){
                ans += rightMax-height[r];
                r--;
            }
            else{
                ans += leftMax-height[l];
                l++;
            }
        }

        return ans;
    }
};