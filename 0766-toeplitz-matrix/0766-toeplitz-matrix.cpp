class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        for(int i = 0;i<c-1;i++){
            for(int j = 0;j<r-1;j++){
                if(mat[j][i] != mat[j+1][i+1])
                    return false;
            }
        }
        return true;
    }
};