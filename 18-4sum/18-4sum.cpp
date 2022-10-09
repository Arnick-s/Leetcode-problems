class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        if(n<4)return {};
        for(int first = 0;first<n-3;first++){
            for(int forth = 3;forth<n;forth++){
                int second = first+1;
                int third = forth - 1;
                while(second<third){
                    long long sum = (long long)nums[first]+(long long)nums[second]+(long long)nums[third]+(long long)nums[forth];
                    if(sum == target)
                    {
                        ans.insert({nums[first],nums[second++],nums[third],nums[forth]});
                    }
                    else if(sum<target){
                        second++;
                    }
                    else {
                        third--;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};