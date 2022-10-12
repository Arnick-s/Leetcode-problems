class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) {
            return (nums[0]<nums[1])?nums[0]:nums[1];
        }
        int l = 0;
        int r = n-1;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(nums[mid] == nums[r]){
                if(nums[mid] == nums[l]){
                    while(nums[mid]==nums[l] && l<r)l++;
                    if(nums[l]<nums[l-1])l--;
                    if(l<mid)r = mid;
                }else{
                    r = mid;
                }
            }else if(nums[mid]>nums[r])l = mid;
            else r = mid;
        }
        if(nums[l]<nums[r])return nums[l];
        return nums[r];
    }
};