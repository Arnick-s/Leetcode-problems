class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        
        for(auto &it: grid)
            for(auto &ii:it)
                if(ii < 0) cnt++;
        return cnt;
    }
};