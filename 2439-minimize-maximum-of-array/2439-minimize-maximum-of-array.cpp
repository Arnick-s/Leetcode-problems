class Solution {
public:

    bool fun(int x,vector<int>&nums){
        int n = nums.size();
        vector<long long> temp(n);
        for(int i = 0;i<n;i++){
            temp[i] = (long long)nums[i];
        }
        for(int i = 0;i<n-1;i++){
            long long r = temp[n-1 - i]-x;
            if(r<0)r=0;
            temp[n-1 - i - 1]+=r;
        }
        if(temp[0]<=x)return true;
        return false;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int l = -1 ;
        int r = 1000000000;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(fun(mid,nums)){
                r = mid;
            }else{
                l = mid;
            }
        }
        return r;
    }
};