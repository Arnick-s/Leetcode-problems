class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int,int> hash;
        vector<int> res(n,-1);
        
        for(int i = 0 ;i<n;i++){
            hash[intervals[i][0]] = i;
        }
        for(int i = 0;i<n;i++){
            auto it = hash.lower_bound(intervals[i][1]);
            if(it != hash.end())
                res[i] = it->second;
        }
        return res;
    }
};