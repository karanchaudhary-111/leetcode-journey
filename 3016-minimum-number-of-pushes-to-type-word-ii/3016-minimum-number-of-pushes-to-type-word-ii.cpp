class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();

        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++){
            int val = (word[i] - 'a');
            freq[val]++;
        }

        int pushes = 0;

        sort(freq.begin(), freq.end(), greater<int>());

        for(int i = 0; i < 26; i++){
            pushes += (i/8 + 1) * freq[i];
        }

        return pushes;
    }
};