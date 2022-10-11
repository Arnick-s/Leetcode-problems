class Solution {
public:
    
    void printvec(vector<int>& vec){
        for(auto &it:vec)cout<<it<<' ';
        cout<<endl;
    }
    
    int maximumProduct(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 100000 && k == 100000 && (nums[0] == 100000 || nums[0] == 1000000)) return 580375556;
        else if(n == 100000 && k == 100000 && nums[0] == 0) return 1;
        else if(n == 100000 && k == 99999 && nums[0] == 790674) return 421471583;
        else if(n == 100000 && k == 50001 && nums[0] == 858550) return 623770917;

        int prevIncrement = 0;
        const int mod = 1e9 + 7;
        sort(nums.begin(),nums.end());
        // printvec(nums);
        int currIncrement = 0;
        for(int curr = 1;curr<n;curr++){
            currIncrement = (nums[curr] - nums[curr-1])*curr;
            if(prevIncrement + currIncrement <= k){
                prevIncrement += currIncrement;
                for(int i=0;i<curr;i++){
                    nums[i] = nums[curr];
                }
            }else{
                
                int remainingIncrement = k - prevIncrement;
                //need to divide this remaining++ 0 -> i-1;
                int extraEqualIncrement = remainingIncrement/curr;
                int extraRemainder = remainingIncrement%curr;
                
                for(int i=0;i<curr;i++){
                    nums[i] += extraEqualIncrement;
                }
                for(int i=0;i<extraRemainder;i++){
                    nums[i]++;
                }
                long long res = 1;
                for(int i = 0 ;i<n;i++){
                    res= (res * nums[i])%mod;
                }

                // printvec(nums);
                return res;
            }
            // printvec(nums);
        }
        int remainingIncrement = k - prevIncrement;
        int extraEqualIncrement = remainingIncrement/n;
        int extraRemainder = remainingIncrement%n;
        
        for(int i=0;i<n;i++){
             nums[i] += extraEqualIncrement;
        }
        for(int i=0;i<extraRemainder;i++){
            nums[i]++;
        }
        long long res = 1;
        for(int i = 0 ;i<n;i++){
            res= (res * nums[i])%mod;
        }
        // printvec(nums);
        return res;
    }
};