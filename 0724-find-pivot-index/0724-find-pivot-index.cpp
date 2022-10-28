class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+2,0);
        for(int i = 0 ;i<n;i++){
            hash[i+1] = nums[i]+hash[i];
        }
        for(int i = 0;i<n;i++){
            if(hash[i] == hash[n] - hash[i+1])
                return i;
        }
        return -1;
    }
};