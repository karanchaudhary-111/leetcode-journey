class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        int n = rowIndex;
        vector<vector<int>> ans;
        vector<int> res;

        for(int i = 0; i <= n; i++){

            vector<int> temp(i+1, 1);

            for(int j = 1; j < temp.size()-1; j++){

                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            if(i == n){
                res = temp;
            }

            ans.push_back(temp);
        }

        return res;
    }
};