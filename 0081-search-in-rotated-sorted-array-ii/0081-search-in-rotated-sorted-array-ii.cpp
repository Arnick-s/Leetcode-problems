class Solution {
public:
    
    bool binarySearch(vector<int>& nums,int l,int r, int& target){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid]>target){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        
        // if(nums.size() == 1) return nums[0]==target;
        int n = nums.size();
        int l = 0;
        int r = nums.size()-1;
        if(n<3){
            // cout<<"how is it here"<<endl;
            if(n == 1) return nums[0]==target;
            else{
                return target == nums[0] || target == nums[1];}
        }
        while(r-l>1){
            int mid = l + (r-l)/2;
            // cout<<l<<' '<<r<<endl;
        if(nums[mid] == nums[r] ){
            if(nums[mid] == nums[l]){
                while(nums[l]==nums[mid] && l<r){l++;}
                if(nums[l]<nums[l-1])l--;
                if(mid<=l){}
                else{
                    r = mid;
                }
            }else{
                r = mid;
            }
        }
        if(nums[mid]>nums[r])
            l = mid;
        
        else if(nums[mid]<nums[r])
        {
            // cout<<"r == mid"<<endl;
            r = mid;
        }
    }
        // cout<<r;
    int R = nums.size()-1;
    l = r;
    r--;
    int L = 0;
        // cout<<"juat above return"<<endl;
        // cout<<L<<' '<<r<<' '<<l<<' '<<R<<endl;
    return  binarySearch(nums,L,r,target)
            || binarySearch(nums,l,R,target);
    }
};