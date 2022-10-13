class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        
        int n = citations.size();
        int r = n;
        int l = -1;
        
        while(r-l>1){
            int mid = l + (r-l)/2;
            
            if(citations[mid] >= n - mid){
                r = mid;//can be a ans
            }else{
                l = mid;
            }
        }
        return n-r;
    }
};