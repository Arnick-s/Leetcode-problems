class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> hash(26,0);
        for(auto &it:s){
            hash[it - 'a']++;
        }
        int check = 0;
        for(auto &it:hash){
            if(check == 0 && it > 0)
                check = it;
            else if(it>0 && check != it)return false;
        }
        return true;
    }
};