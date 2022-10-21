class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
    unordered_map<int,int> nmap;
    for (int i = 0; i <nums.size();i++)
    {
        
        if(nmap.count(nums[i]) == 1){
            if(i - nmap[nums[i]] <= k)
                return true;
        }
        nmap[nums[i]] = i;
    }
    
    return false; 
    }
};