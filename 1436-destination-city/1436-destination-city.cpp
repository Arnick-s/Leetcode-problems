class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,string>hash;
        int n = paths.size();
        
        for(auto &it:paths){
            hash[it[0]] = it[1];
        }
        
        auto ii = hash.find(paths[0][1]);
        string res = paths[0][1];
        while(ii!=hash.end()){
            res = ii->second;
            ii = hash.find(ii->second);
            
        }
        return res;
    }
};