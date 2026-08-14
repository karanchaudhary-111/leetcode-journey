class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.size();
        int i = 0;
        int j = 0;

        vector<int> vec(26, 0);

        int ans = 0;

        while(j < n){

            vec[s[j] - 'a']++;

            while(vec[s[j] - 'a'] > 2){
                vec[s[i] - 'a']--;
                i++;
            }
            ans = max(ans, j -i + 1);
            j++;
        }

        return ans;
    }
};