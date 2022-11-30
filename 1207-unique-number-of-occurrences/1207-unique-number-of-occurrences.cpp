class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> hash(2005,0);
        for(auto &it:arr)
            hash[it+1000]++;
        
        vector<int> occ(1005,0);
        for(auto &it:hash)
            if(it!=0)
                occ[it]++;
        
        for(auto &it:occ)
            if(it>1)return false;
        
        return true;
    }
};