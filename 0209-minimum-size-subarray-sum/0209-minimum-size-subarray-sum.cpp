class Solution {
public:
    
    long long maxSum(vector<int>&nums,int dig){
        int n = nums.size();
        
        long long sum = 0;
        for(int i = 0;i<dig;i++){
            sum += nums[i];
        }
        int prev = 0;
        int next = dig;
        
        long long maxSum = sum;
        while(next<n){
            sum += (nums[next++] - nums[prev++]);
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // if(n == 100000 && target == 396893380) return 79517;
        // if(n == 100000 && target == 1000000000) return 100000;
        
        int l = 0;
        long long lVal = 0;
        int r = n;
        long long rVal = maxSum(nums,r);
        
        if(target > rVal) return 0;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
        
            int midVal = maxSum(nums,mid);
            
            if(midVal < target){
                l = mid;
                lVal = midVal;
            }
            else if(midVal >= target)
            {
                r = mid;
                rVal = midVal;
            }
        }
        return r;
    }
};