class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0;i<n/2;i++){
            sum += (mat[i][i] + mat[i][n-1 - i] + mat[n-1 - i][i] + mat[n-1 -i][n-1- i]);
        }
        
        if(n%2 == 1) sum += mat[n/2][n/2];
        return sum;
    }
};