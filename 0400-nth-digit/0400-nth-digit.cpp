class Solution {
public:
    int count_dig(int n){
        return log10(n) + 1;
    }
    
    int findDig(int ans,int rem,int dig){
        rem++;
        while(ans){
            if(dig == rem)
            {
                return ans%10;
            }
            ans/=10;
            dig--;
        }
        return 0;
    }
    int findNthDigit(int n) {
        
        if(n<10)return n;

        long long lesser_dig_count = 9;
        int multiplier = 1;
        while(n>=(lesser_dig_count*multiplier)){
            n -= lesser_dig_count*multiplier;
            lesser_dig_count *= 10;
            multiplier++;
        }
        
        int dig = count_dig(lesser_dig_count);
        n = n-1;
        int rem = n%dig;
        n/=dig;
        
        int ans = pow(10,dig-1);
        ans += n;
        
        return findDig(ans,rem,dig);
    }
};