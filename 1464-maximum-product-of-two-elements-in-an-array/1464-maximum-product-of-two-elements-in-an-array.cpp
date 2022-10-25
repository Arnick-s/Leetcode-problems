class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN,secMax = INT_MIN;
        int n = nums.size();
        for(auto &it:nums){
            //max & secMax
            if(it > max){
                 secMax = exchange(max,it);
            }else if(it<=max && it > secMax)
                secMax = it;
        }
        return (max-1)*(secMax -1);
    }
};