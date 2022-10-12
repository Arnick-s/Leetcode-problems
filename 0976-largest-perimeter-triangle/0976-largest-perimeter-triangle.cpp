class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        //consider the last three;
        for(int i = n-1;i>=2;i--){
            int lar1 = nums[i];
            int lar2 = nums[i-1];
            int lar3 = nums[i-2];
            
            int sum23 = lar2 + lar3;
            if(lar1 >= sum23)continue;
            else return lar1 + sum23;
        }
        return 0;
    }
};