class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> check_allowed(26,false);
        
        for(int i = 0;i<allowed.size();i++){
            check_allowed[allowed[i] - 'a'] = true;
        }
        int n = words.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            bool ok = true;
            for(int j = 0;j<words[i].length();j++){
                if(check_allowed[words[i][j] - 'a']== false){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cnt++;
            }
        }
        return cnt;
    }
};