class Solution {
public:
    string sortString(string s) {
        int n = s.length();
        vector<int> hash(26,0);
        
        for(auto &it:s){
            hash[it - 'a']++;
        }
        string resS = "";
        bool topToDown = true;
        
        while(n>0){
            for(int i = 0;i<26;i++){
                int idx = (topToDown) ? i : 25 - i;
                if(hash[idx]>0)
                {
                    resS.push_back(idx + 'a');
                    hash[idx]--;n--;
                }
            }
            topToDown = !topToDown;
        }
        return resS;
    }
};