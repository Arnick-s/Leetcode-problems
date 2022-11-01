class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        //+1 -> look at right
        //-1 -> look at left
        
        int m = grid[0].size();
        int n = grid.size();
        vector<int> res(m,-1);
        
        for(int jj = 0;jj<m;jj++){
            int j = jj;
            bool ok = true;
            for(int i = 0;i<n;i++){
                if(grid[i][j] == +1){
                    if(j == m-1||grid[i][j+1] == -1){
                        ok = false;
                        break;
                    }
                    j++;
                }
                else{
                    if(j == 0 || grid[i][j-1] == 1){
                        ok = false;
                        break;
                    }
                    j--;
                }
            }
            if(ok)
                res[jj] = j ;
        }
        return res;
    }
};