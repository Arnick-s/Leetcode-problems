class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i_should_be = 1;
        for(int i = 0 ;i<n;i++){
            if(i_should_be != nums[i])
            {
                if(i_should_be - nums[i] == 1)continue;
                break;
            }
            i_should_be ++;
        }
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1])
                return {nums[i],i_should_be};
        }
        return {};
    }
};