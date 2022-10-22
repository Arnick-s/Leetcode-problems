class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = t.length();
        int n = s.length();
        
        unordered_map<char,int> ump;
        for(auto it : t) ump[it]++;
        
        int l = 0;
        int r = 0;
        int start = -1;
        int maxi = 1000000;
        
        while(r<n){
            if(ump[s[r]] > 0)cnt--;
            ump[s[r++]]--;
            
            while(cnt == 0 && l <= r){
                if(maxi > r - l)
                {
                    maxi = r - l;
                    start = l;
                }
                
                if(ump[s[l]] >= 0)cnt++;
                ump[s[l++]]++;
            }
        }
        if(start == -1) return "";
        return s.substr(start,maxi);
    }
};