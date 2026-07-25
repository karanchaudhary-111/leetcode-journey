class Solution {
public:
    int maxProduct(int n) {
        int topMax = 0;
        int secMax = 0;
        while(n!=0){
            int digit = n % 10;
            n/=10;
            if(digit >= topMax){
                secMax = topMax;
                topMax = digit;
            }
            else if(digit > secMax){
                secMax = digit;
            } 
        }
        return topMax * secMax;
    }
};