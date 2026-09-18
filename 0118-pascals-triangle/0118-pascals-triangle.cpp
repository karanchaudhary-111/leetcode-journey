class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        int n = numRows;
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){

            vector<int> temp(i+1);

            for(int j = 0; j < temp.size(); j++){
                if(j == 0 || j == temp.size()-1){
                    temp[j] = 1;
                }else{
                    temp[j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};