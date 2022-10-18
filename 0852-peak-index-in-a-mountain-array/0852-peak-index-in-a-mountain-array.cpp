class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 1;
        int r = n-2;
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid] > arr[mid-1]){
                if(arr[ans]<arr[mid]){
                    ans = mid;
                }
                l = mid + 1;
            }else if(arr[mid]> arr[mid+1]){
                if(arr[ans]<arr[mid]){
                    ans = mid;
                }
                r = mid - 1;
            }
                
        }
        return ans;
    }
};