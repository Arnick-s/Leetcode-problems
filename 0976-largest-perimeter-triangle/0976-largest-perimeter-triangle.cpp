class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        //consider the last three;
        for(int i = nums.size()-1;i>=2;i--){
            int sum = nums[i-1] + nums[i-2];
            if(nums[i] >= sum)continue;
            else return nums[i]+sum;
        }
        return 0;
    }
};