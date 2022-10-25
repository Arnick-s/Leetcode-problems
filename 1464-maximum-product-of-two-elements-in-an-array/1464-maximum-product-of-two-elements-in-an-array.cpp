class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN,secMax = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            //max & secMax
            if(nums[i] > max){
                 secMax = max;
                max = nums[i];
            }else if(nums[i]<=max && nums[i] > secMax)
                secMax = nums[i];
        }
        return (max-1)*(secMax -1);
    }
};