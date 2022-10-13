class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> ans;
        int idx1 = 0;
        int idx2 = 0;
        
        while(idx1<n && idx2<m){
            if(nums1[idx1] == nums2[idx2]){
                ans.push_back(nums1[idx1++]);
                idx2++;
                while(idx1<n && nums1[idx1] == nums1[idx1 - 1])
                    idx1++;
                while(idx2<m && nums2[idx2] == nums2[idx2 - 1])
                    idx2++;
            }
            else if(nums1[idx1]<nums2[idx2]){
                idx1++;
            }else{
                idx2++;
            }
        }
        return ans;
        
    }
};