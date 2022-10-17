class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> hash(1001,false);
        for(auto &it:arr){
            hash[it] = true;
        }
        int cnt = 0;
        for(int i = 1;i<1001;i++){
            if(!hash[i])cnt++;
            if(cnt == k)return i;
        }
        
        return 1000 + k - cnt;
    }
};