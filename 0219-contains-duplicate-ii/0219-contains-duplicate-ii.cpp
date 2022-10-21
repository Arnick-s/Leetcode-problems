class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> visited;
        int n = nums.size();
        
        //inserting starting k+1 ele
        for(int i = 0; i<k+1 && i<n ;i++){
            if(visited.find(nums[i]) == visited.end())
                visited.insert(nums[i]);
            else
                return true;
        }

        //sliding window
        int l = 0;
        int r = k + 1;
        while( r < n ){
            visited.erase(visited.find(nums[l]));
            l++;
            if(visited.find(nums[r]) == visited.end())
                visited.insert(nums[r]);
            else
                 return true;
            r++;
        }
        return false;
    }
};