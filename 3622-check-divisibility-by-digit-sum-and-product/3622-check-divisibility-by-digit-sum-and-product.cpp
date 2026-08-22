class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prd = 1;

        int store = n;

        while(n > 0){
            int digit = n % 10;

            sum += digit;
            prd *= digit;

            n = n/10;
        }
        int val = sum + prd;

        if(store % val == 0){
            return true;
        }

        return false;
    }
};