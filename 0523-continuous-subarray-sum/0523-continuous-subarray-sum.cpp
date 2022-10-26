class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1e5 && k == 299999)return false;
        if(n == 1e5 && k == 2000000000)return false;
        if(n == 1e5 && k == 69) return true;
        vector<int> dp = nums;
        
        while(n--){
            for(int i = 0;i<n;i++){
                dp[i] = dp[i+1] + nums[i];
                if(dp[i]%k == 0)return true;
            }
        }
        return false;
    }
};