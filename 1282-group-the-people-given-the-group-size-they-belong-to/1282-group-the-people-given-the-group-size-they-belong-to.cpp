class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> group;
        vector<vector<int>> res;
        
        for(int i = 0;i < groupSizes.size(); ++i){
            group[groupSizes[i]].push_back(i);
        }
        for(auto & it : group){
            for(auto curr = it.second.begin(); curr != it.second.end(); curr += it.first){
                res.push_back(vector<int>(curr,curr+it.first));
            }
        }
        return res;
    }
};