class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n-1;
        int ans = -1;

        while(l < r){
            int h = min(height[l], height[r]);

            ans = max(ans, (r - l)*h);

            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }

        return ans;
    }
};