class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        nums.push_back(7);
        int n = nums.size();
        int l = -1;
        int r = n-1;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
            
            if(nums[mid]>=target){
                r = mid;
            }
            else if(nums[mid]<target){
                l = mid;
            }
        }
        int leftIdx = l;
        l = -1;
        r = n-1;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
            
            if(nums[mid]<=target)
                l = mid;
            else r = mid;
        }
        int rightIdx = r;
        vector<int> res(rightIdx - leftIdx - 1);
        int x = 0;
        while(++leftIdx<rightIdx){
            res[x++] = leftIdx;
        }
        return res;
    }
};