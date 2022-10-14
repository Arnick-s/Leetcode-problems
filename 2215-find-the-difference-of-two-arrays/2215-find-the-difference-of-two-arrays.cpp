class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> hash(2001,false);
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i = 0;i<n;i++){
            hash[nums1[i] + 1000] = true;
        }
        for(int i = 0;i<m;i++){
            hash[nums2[i] + 1000] = false;
        }
        vector<int> res1;
        for(int i = 0;i<2001;i++){
            if(hash[i])res1.push_back(i - 1000);
            hash[i] = false;
        }
        
        for(int i = 0;i<m;i++){
            hash[nums2[i] + 1000] = true;
        }
        for(int i = 0 ;i<n;i++){
            hash[nums1[i] + 1000] = false;
        }
        vector<int> res2;
        for(int i = 0;i<2001;i++){
            if(hash[i])res2.push_back(i - 1000);
        }
        return {res1,res2};
    }
};