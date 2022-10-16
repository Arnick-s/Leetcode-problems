class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        int n = nums.size();
        int fh = INT_MIN,sh = INT_MIN;
        int fl = INT_MAX,sl = INT_MAX;
        for(int i = 0;i<n;i++){
            int num = nums[i];
            if(num>fh){
                sh = fh;
                fh = num;
            }else if(num>sh)
                sh = num;
            if(num<fl){
                sl = fl;
                fl = num;
            }else if(num<sl)
                sl = num;
        }
        return fh*sh - fl*sl;
    }
};