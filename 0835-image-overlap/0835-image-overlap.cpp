class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        set<pair<int,int>> img1loc;
        int n = img1.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(img1[i][j] == 1)
                    img1loc.insert({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        int maxi=0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)
            {
                if(img2[i][j] == 1){
                    for(auto &it: img1loc){
                        mp[{it.first - i,it.second - j}]++;
                    }   
                }
            }
        }
        for(auto &it:mp){
            maxi = max(it.second,maxi);
        }
        return maxi;
    }
};