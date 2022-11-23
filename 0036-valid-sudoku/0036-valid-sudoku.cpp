class Solution {
public:
    
    bool check_box(vector<vector<char>>&board){
        for(int i = 0;i<7;i+=3){
            for(int j = 0;j<7;j+=3){
                vector<bool>check(10,false);
                for(int ii = i;ii<i+3;ii++){
                    for(int jj = j;jj<j+3;jj++){
                        if(board[ii][jj] == '.')continue;
                        
                        if(check[board[ii][jj] - '0'])
                            return false;
                        else check[board[ii][jj] - '0'] = true;
                    }
                }
                vector<bool> checki(10,false);
                for(int ii = j;ii<j+3;ii++){
                    for(int jj = i;jj<i+3;jj++){
                        if(board[ii][jj] == '.')continue;
                        if(checki[board[ii][jj] - '0'])
                            return false;
                        else checki[board[ii][jj] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i<9;i++){
            vector<bool> check(10,false);
            vector<bool> checki(10,false);
            for(int j = 0;j<9;j++){
                
                if(board[i][j]!='.'){if(check[board[i][j] - '0'])
                    return false;
                else check[board[i][j] - '0'] = true;}
                    
                if(board[j][i]!='.'){if(checki[board[j][i] - '0'])
                    return false;
                else checki[board[j][i] - '0'] = true; }
            }
        }
        
        
        return check_box(board);
    }
};