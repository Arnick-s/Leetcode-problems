class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        for(int i = 0;i<n-1;i++){
            string tempS = "";
            int cnt = 1;char prev = s[0];
            for(int j = 1;j<s.length();j++){
                if(s[j]==prev){
                    cnt++;
                }else{
                    tempS += (to_string(cnt));
                    tempS += prev;
                    cnt = 1;
                }
            prev = s[j];    
            }
            tempS += (to_string(cnt));
            tempS += prev;
            s = tempS;
            tempS = "";
        }
        return s;
    }
};