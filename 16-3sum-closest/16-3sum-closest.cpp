class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        
        sort(nums.begin(),nums.end());
        
        int closest = nums[0]+nums[1]+nums[2];
        for(int first = 0;first<n-2;first++){
            if(first>0 && nums[first] == nums[first - 1])continue;
            int second = first + 1;
            int third = n-1;
            
            while(second < third){
                
                int currSum = nums[first] + nums[second] + nums[third];
                if( currSum == target) return target;
                if(abs(currSum - target) < abs(closest - target))
                    closest = currSum;
                if(currSum < target) second++;
                else third--;
            }
        }
        return closest;
    }
};