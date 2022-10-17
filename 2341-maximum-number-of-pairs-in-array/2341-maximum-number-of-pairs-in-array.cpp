class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<bool> hash(101,false);
        int cnt = 0;
        for(auto &it:nums){
            if(hash[it] == false)
                hash[it] = true;
            else{
                cnt++;
                hash[it] = false;
            }
        }
        int leftcnt = 0;
        for(int i = 0;i<101;i++){
            if(hash[i] == true)
                leftcnt ++;
        }
        return {cnt,leftcnt};
    }
};