class Solution {
public:
    int maxProduct(int n) {

        int ans = 1;
        vector<int> temp;
        
        while(n > 0){
            int digit = n % 10;
            n = n/10;
            temp.push_back(digit);
        }
        sort(begin(temp), end(temp));

        int x = temp.size();

        ans = temp[x-1] * temp[x -2];

        return ans;
    }
};