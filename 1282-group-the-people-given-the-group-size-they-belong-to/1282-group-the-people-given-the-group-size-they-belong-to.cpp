class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mp;
        int n = groupSizes.size();
        vector<vector<int>> res;
        
        for(int i = 0;i<n;i++){
            if(mp.find(groupSizes[i]) == mp.end()){
                mp[groupSizes[i]] = {i};
            }else{
                mp[groupSizes[i]].push_back(i);
            }
            
            if(mp.find(groupSizes[i])->second.size() == groupSizes[i]){
                res.push_back(mp[groupSizes[i]]);
                mp.erase(groupSizes[i]);
            }
        }
        for(auto &it: mp){
            res.push_back(it.second);
        }
         return res;   
    }
};