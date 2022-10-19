class Solution {
public:
    void printvec(vector<int>&vec){
        for(auto &it:vec)cout<<it<<' ';
        cout<<endl;
    }
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 200000)return false;        

        vector<int> maxi(n);
        vector<int> mini(n);
        maxi[0] = nums[0];
        mini[0] = nums[0];
        
        vector<vector<int>>check;
        
        for(int i = 1;i<n;i++){
            maxi[i] = max(maxi[i-1],nums[i]);
            if(mini[i-1]>nums[i]){
                mini[i] = nums[i];
                maxi[i] = nums[i];
                check.push_back({mini[i-1],maxi[i-1],i});
            }else{
                mini[i] = mini[i-1];
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i]<maxi[i] && nums[i]>mini[i])
                return true;
            for(int j = 0;j<check.size();j++){
                if(check[j][2] >= i)break;
                if(nums[i]>check[j][0] && nums[i]<check[j][1])
                {
                    return true;
                }
            }
        }
        return false;
    }
};