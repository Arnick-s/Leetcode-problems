class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();

        int cnt = 0;
        for(int i = 0;i<n;i++){
            
            char temp = tolower(s[i]);
            if(!(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'))
                continue;
            
            i<n/2 ? cnt++:cnt--;   
            
        }
        return cnt==0 ? true: false;
    }
};