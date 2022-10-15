class Solution {
public:
    string decodeMessage(string s, string m) {
        int n = s.size();
        vector<char>KEY(26);
        vector<bool>seen(26,false);
        
        int x = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == ' ')continue;
            if(seen[s[i]-'a'] == false)
            {
                KEY[s[i]-'a'] = x++ + 'a';
                seen[s[i]-'a'] = true;
            }
        }
        
        for(int i = 0;i<m.size();i++){
            if(m[i]!=' '){
                m[i] = KEY[m[i]-'a'];
            }
        }
        return m;
    }
};