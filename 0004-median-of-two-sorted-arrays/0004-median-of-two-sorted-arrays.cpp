class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //assuming total size = odd
        int n1 = nums1.size(),n2 = nums2.size();
        if((n1 + n2 )%2 == 1){
            int median_idx = (n1 + n2)/2;
            int steps = median_idx -2;

            int idx1 = 0;
            int idx2 = 0;

            int buffer;
            int x = 0;
            while(idx1<n1 && idx2<n2){
                if(nums1[idx1]<=nums2[idx2])
                {
                    buffer = nums1[idx1++];
                    x++;
                }else{
                    buffer = nums2[idx2++];
                    x++;
                }
                if(x == median_idx +1) return (double)buffer;
            }
            while(idx1<n1){
                buffer = nums1[idx1++];
                x++;
                if(x == median_idx +1) return (double)buffer;

            }
            while(idx2<n2){
                buffer = nums2[idx2++];
                x++;
                if(x == median_idx +1) return (double)buffer;
            }
            return 1.00;
        }
        else{
            int median_idx = (n1 + n2)/2;
            int steps = median_idx -2;

            int idx1 = 0;
            int idx2 = 0;

            int buffer =0;
            int prev_buffer;
            int x = 0;
            while(idx1<n1 && idx2<n2){
                if(nums1[idx1]<=nums2[idx2])
                {   prev_buffer = buffer;
                    buffer = nums1[idx1++];
                    x++;
                }else{
                    prev_buffer = buffer;
                    buffer = nums2[idx2++];
                    x++;
                }
                if(x == median_idx +1) return (double)(buffer + prev_buffer)/2;
            }
            while(idx1<n1){
                prev_buffer = buffer;
                buffer = nums1[idx1++];
                x++;
                if(x == median_idx +1) return (double)(buffer + prev_buffer)/2;

            }
            while(idx2<n2){
                prev_buffer = buffer;
                buffer = nums2[idx2++];
                x++;
                if(x == median_idx +1) return (double)(buffer + prev_buffer)/2;
            }
            return 1.00;
        }
    }
};