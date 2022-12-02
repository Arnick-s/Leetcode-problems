class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        
        if(n1!=n2)return false;
        
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        
        vector<bool> seen1(26,false);
        vector<bool> seen2(26,false);
        
        for(int i = 0;i<n1;i++){
            hash1[word1[i]-'a']++;
            hash2[word2[i]-'a']++;
            
            seen1[word1[i] - 'a'] = true;
            seen2[word2[i] - 'a'] = true;
        }
        
        sort(hash1.begin(),hash1.end());
        sort(hash2.begin(),hash2.end());
        
        return hash1 == hash2 && seen1 == seen2 ? true : false;
    }
};