class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        unordered_set<int> zeroRow;
        unordered_set<int> zeroCol;

        for(int i = 0; i < row; i++){
            for(int j =  0; j < col; j++){
                if(matrix[i][j] == 0){
                    zeroRow.insert(i);
                    zeroCol.insert(j);
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(zeroRow.find(i) != zeroRow.end() || zeroCol.find(j) != zeroCol.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};