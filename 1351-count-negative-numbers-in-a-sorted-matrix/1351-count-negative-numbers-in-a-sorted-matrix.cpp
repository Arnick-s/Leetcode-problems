class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int ans = m;
        for(auto &nums: grid){
            int l = 0;
            int r = nums.size() - 1;
            if(ans < r)r=ans;
            while(l<=r){
                int mid = l + (r-l)/2;
                
                if(nums[mid]<0){
                    ans = mid;
                    r = mid-1;
                }
                else{
                    l = mid + 1;
                }
            }
            res += m-ans;
        }
        return res;
    }
};