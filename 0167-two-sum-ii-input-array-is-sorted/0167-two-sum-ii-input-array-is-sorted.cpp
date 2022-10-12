class Solution {
public:
    
    int binarySearch(vector<int>&nums,int l,int r,int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            int idx = binarySearch(nums,i+1,n-1,target - nums[i]);
            if(idx != -1)
                return {i+1,idx+1};
        }
        return {-1};
    }
};