class Solution {
public:
    string solve(string s, int st, int en){
        vector<int> freq(26, 0);

        string temp = "";

        for(int i = st; i < en; i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                temp += (i + 'a');
                freq[i]--;
            }
        }

        return temp;
    }

    string smallestPalindrome(string s) {
        int n = s.size();

        if(n == 1){
            return s;
        }

        string mid;

        if(n %  2 != 0){
            mid = string(1, s[n/2]);
        }else{
            mid = "";
        }

        string firstHalf = solve(s, 0, (n/2));

        string secondHalf = firstHalf;;

        reverse(begin(secondHalf), end(secondHalf));


        return firstHalf + mid + secondHalf;
    }
};