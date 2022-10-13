class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        sort(citations.begin(),citations.end());
        
        int l = -1;
        int r = n;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
            
            if(citations[mid] >= n - mid){
                r = mid;
            }else l = mid;
        }
        return n - r;
    }
};