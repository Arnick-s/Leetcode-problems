class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> ans;
        vector<int> v;
        unordered_set<int> a,b,c;
        for(auto & ak : nums1)a.insert(ak);
        
        for(int & bk : nums2){
            b.insert(bk);
            if(a.find(bk) != a.end())ans.insert(bk);
        }
        for(int & bk : nums3){
            if(a.find(bk) != a.end() or b.find(bk) != b.end())ans.insert(bk);
        }
        for(auto & ak : ans)v.push_back(ak);
        
        return v;
        
    }
};