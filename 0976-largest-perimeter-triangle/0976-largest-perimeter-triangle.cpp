class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        //consider the last three;
        for(int i = n-1;i>=2;i--){
            
            if(nums[i] >= nums[i-1]+nums[i-2])continue;
            else return nums[i]+nums[i-1] + nums[i-2];
        }
        return 0;
    }
};