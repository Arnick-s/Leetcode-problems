class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(n==1)return strs[0];
        string mostcommon = strs[0];
        for(int i = 1;i<n;i++){
            int m = min(mostcommon.length(),strs[i].length());
            string tempcommon = "";
            for(int j = 0;j<m;j++ ){
                if(mostcommon[j] == strs[i][j])
                {
                    tempcommon.push_back(mostcommon[j]);
                }
                else
                    break;
            }
            mostcommon = tempcommon;
            if(mostcommon.length() == 0) return "";
        }
        return mostcommon;
    }
};