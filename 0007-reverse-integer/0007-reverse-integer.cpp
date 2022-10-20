class Solution {
public:
    int reverse(int x) {
        
        int multiplier = 1;
        if(x<0){
            multiplier = -1;
            if(x == INT_MIN)return 0;
            x *= multiplier;
        }
        
        int res = 0;
        while(x){
            if(res>INT_MAX/10 || res == INT_MAX && x%10 > INT_MAX%10){
                return 0;
            }else{  
                res = res*10 + x%10;
                x/=10;
            }
        }
        return res*multiplier;
    }
};