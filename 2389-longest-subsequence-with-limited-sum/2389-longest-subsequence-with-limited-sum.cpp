class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        //presum
        int n = nums.size();
        int m = queries.size();
        for(int i = 1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        //smaller than or equal to
        vector<int> res(m);int idx = 0;
        for(auto &t:queries){
            auto it = --upper_bound(nums.begin(),nums.end(),t) - nums.begin();
            
            res[idx++] = it+1;
        }
        return res;
    }
};