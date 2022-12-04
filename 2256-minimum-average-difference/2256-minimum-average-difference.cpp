class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
            
            int n = nums.size();
            
            vector<long long> dp(n+1);
            dp[0] = 0;
            for(int i = 0;i<n;i++){
                    dp[i+1] = dp[i]+nums[i];
            }
            
            int min_idx;
            int mini = INT_MAX;
            
            for(int i = 0;i<n;i++){
                    
                    if(i == n-1){
                            if(mini>(dp[n]/n)){
                                    return n-1;
                            }
                            break;
                    }
                    
                    long long left = dp[i+1]/(i+1);
                    long long right = (dp[n] - dp[i+1])/(n-i-1);
                    
                    // cout<<"left = "<<left <<"  right = "<<right <<' '<<"abs  = "<<abs(left - right)<<endl;
                    if(abs(left - right) < mini){
                            mini = abs(left-right);
                            min_idx = i;
                    }
            }
            return min_idx;
    }
};