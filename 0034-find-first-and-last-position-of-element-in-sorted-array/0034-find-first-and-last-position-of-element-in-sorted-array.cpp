class Solution {
public:
    
int findIndex(vector<int>& nums, int target,int &r,int& l)
    {
        
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
           // cout<<nums[mid]<<endl;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
    int l=0;
    int r=nums.size()-1;
    int tempr=findIndex(nums,target,r,l);
        if (tempr==-1)
            return {-1,-1};
    int templ=tempr;
    //int temp=INT_MAX;
    while(l<tempr)
    {
        int mid=l+(tempr-l)/2;
        if(nums[mid]==target){
            if(tempr==mid)
            break;
            else
            tempr=mid;
        }
        else
            l=mid+1;
        
    }

    while(templ<r)
{
    int mid=ceil(templ+(double)(r-templ)/2);
    if(nums[mid]==target)
    {
        if(templ==mid)
        break;
        else
        templ=mid;}
    else r=mid-1;  
}return {tempr,templ};
    }
};