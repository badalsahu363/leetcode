class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size() ,cols = matrix[0].size();
        vector<int>dumm1(rows,-1);
        vector<int>dumm2(cols,-1);
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(matrix[i][j] == 0){
                    dumm1[i] = 0;
                    dumm2[j] = 0;
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dumm1[i] ==0 || dumm2[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};