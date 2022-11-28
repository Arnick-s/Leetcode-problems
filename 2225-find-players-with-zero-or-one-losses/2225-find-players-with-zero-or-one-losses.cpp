class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> win(100000+5,0);
        vector<int> lose(100000+5,0);
        
        for(auto &it: matches){
            win[it[0]]++;
            lose[it[1]]++;
        }
        
        vector<int>always_win;
        vector<int>one_lose;
        
        for(int i = 0;i<100000+5;i++){
            if(lose[i] == 1)one_lose.push_back(i);
        }
        
        for(int i = 0;i<100000+5;i++){
            if(win[i]>0 && lose[i] == 0){
                always_win.push_back(i);
            }
        }
        return {always_win,one_lose};
    }
};