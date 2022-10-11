class Solution {
public:
    
    int binarySearch(vector<int>&nums,int &l,int &r,int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target){
                r = mid-1;
            }else l = mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = -1;
        int r = n-1;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
            
            if(nums[mid]<=nums[r]){
                r = mid;
            }
            else if(nums[mid]>nums[r])
            {
                l = mid;
            }
        }
        
        int L = r;
        int R = r-1;

        //l->R and then L->r
        l = 0;
        r = n-1;
        int idx1 = binarySearch(nums,l,R,target);
        int idx2 = binarySearch(nums,L,r,target);
        
        if(idx1 == idx2 ) return idx1;
        if(idx1 != -1) return idx1;
        return idx2;
    }
};