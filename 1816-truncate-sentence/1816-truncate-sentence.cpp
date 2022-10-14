class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length();
        
        string res = "";
        int blankCnt = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == ' '){
                blankCnt ++;
                if(blankCnt == k)
                    break;
            }
            res += s[i];
        }
        return res;
    }
};