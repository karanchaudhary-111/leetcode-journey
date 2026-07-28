class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        int mid =  n/2;
        int count[26] = {0};

        // ye  first half ke char ki freq store kiya
        for(int i = 0; i < mid; i++){
            count[s[i] - 'a']++;
        }

        // ye first half ko lexicographically arrange kr diya
        int idx = 0;
        for(int i = 0; i < 26; i++){
            while(count[i] > 0){
                s[idx++] = (i + 'a');
                count[i]--;
            }
        }

        // ye second half ko set kr diya
        for(int i = 0; i < mid; i++){
            s[n-i-1] = s[i];
        }

        return s;
    }
};