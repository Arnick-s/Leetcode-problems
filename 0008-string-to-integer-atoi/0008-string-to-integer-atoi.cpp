//1. ignore zero and blank_space in the start
//2. s[i] - '0' will give us the integer
class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        int n = s.length();
        
        while(idx<n && s[idx] == ' ')idx++;
        
        
        int multiplier = 1;
        
        if(s[idx] == '-'){
            multiplier = -1;
            idx++;
        }
        else if(s[idx] == '+'){
            multiplier = 1;
            idx++;
        }
        while(idx<n && s[idx] == '0')idx++;
        
        
        long long res = 0;
        bool seen_dec = false;
        int dec = 0;
        while(idx<n){
            if(s[idx]<'0' || s[idx]>'9') break;
            res = res*10 + s[idx] - '0';
            if(res>INT_MAX){
                if(multiplier == -1)return INT_MIN;
                else{
                    return INT_MAX;
                }
            }
            idx++;
        }
        
        return res*multiplier;
    }
};