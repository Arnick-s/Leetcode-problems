class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length()/2;
        if(n==0) return "";
        
        for(int i = 0;i<n;i++){
            if(palindrome[i]!='a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[palindrome.length()-1] = 'b';
        return palindrome;        
    }
};