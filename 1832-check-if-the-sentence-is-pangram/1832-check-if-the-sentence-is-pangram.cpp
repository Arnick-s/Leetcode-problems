class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> hash(26,false);
        
        for(auto &it:sentence)
            hash[it - 'a'] = true;
        
        for(int i = 0;i<26;i++)
            if(!hash[i])
                return false;
        return true;
    }
};