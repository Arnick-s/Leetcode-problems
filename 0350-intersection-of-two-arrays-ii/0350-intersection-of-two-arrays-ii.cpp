class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> ans;
        int idx1 = 0;
        int idx2 = 0;
        
        while(idx1<n && idx2<m){
            int a = nums1[idx1];
            int b = nums2[idx2];
            
            if(a==b){
                idx1++;
                idx2++;
                ans.push_back(a);
            }
            else if(a<b){
                idx1++;
            }else{
                idx2++;
            }
        }
        return ans;
    }
};