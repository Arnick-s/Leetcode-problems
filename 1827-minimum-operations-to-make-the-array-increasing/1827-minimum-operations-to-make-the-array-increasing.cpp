class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int op = 0;//cnt
        for(int i = 1;i<n;i++){
            int tempcnt = max(0,prev - nums[i] + 1);
            op += tempcnt;
            prev = nums[i] + tempcnt;
        }
        return op;
    }
};