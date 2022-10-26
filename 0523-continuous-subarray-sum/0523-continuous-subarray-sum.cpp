class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> visited;
        int mod = 0;
        int prev = 0;
        
        for(auto &it:nums){
            mod = (mod + it)%k;
            if(visited.find(mod) != visited.end()) return true;
            visited.insert(prev);
            prev = mod;//to subarray of len 1;
        }
        return false;
    }
};