class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        map<int, vector<int>> mp;

        vector<int> ans;

        for(int i =  0; i < row; i++){
            for(int j = 0; j < col; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        for(auto &it: mp){
            if(it.first % 2 == 0){
                reverse(it.second.begin(), it.second.end());
            }

            for(auto & num : it.second){
                ans.push_back(num);
            }
        }

        return ans;
    }
};