class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> hash(1001,0);
        int n = nums.size();
        
        for(auto &it: nums){
            for( auto &i : it){
                hash[i]++;
            }
        }
        vector<int> res;
        for(int i = 0;i<1001;i++){
            if(hash[i] == n) res.push_back(i);
        }
        return res;
    }
};