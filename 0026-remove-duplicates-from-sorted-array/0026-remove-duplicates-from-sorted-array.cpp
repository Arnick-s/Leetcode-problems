class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        //two ptr approach
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr2 < n){
            if(nums[ptr2] == nums[ptr1])ptr2++;
            else nums[++ptr1] = nums[ptr2++];
        }
        return ptr1+1;
    }
};