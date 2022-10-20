class Solution {
public:
    void extendPalindrome(string&s,int i, int j,int &low,int &maxLen){
        while(i>=0 && j<s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        
        if(maxLen < j - i - 1){
            low = i + 1;
            maxLen = j - i - 1;
        }
        return;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2) return s;
        int low;
        int maxLen = 0;
        for(int i = 0;i<n-1;i++){
            extendPalindrome(s,i,i,low,maxLen);
            extendPalindrome(s,i,i+1,low,maxLen);
        }
        return s.substr(low,maxLen);
    }
};