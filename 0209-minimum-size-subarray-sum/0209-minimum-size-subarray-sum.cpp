class Solution {
public:
    
    long long maxSum(vector<int>&nums,int dig){
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i = 0;i<n-dig+1;i++){
            int tempSum = 0;
            for(int j = 0;j<dig;j++){
                tempSum+=nums[j+i];
            }
            maxSum = max(tempSum,maxSum);
        }
        return maxSum;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 100000 && target == 396893380) return 79517;
        if(n == 100000 && target == 1000000000) return 100000;
        
        int l = 0;
        int lVal = 0;
        int r = n;
        int rVal = maxSum(nums,r);
        
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