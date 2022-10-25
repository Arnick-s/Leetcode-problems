class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wrd1_idx = 0;
        int wrd2_idx = 0;
        int wrd1 = 0;
        int wrd2 = 0;
        
        while(wrd1 < word1.size() && wrd2 < word2.size()){
            if(word1[wrd1][wrd1_idx] != word2[wrd2][wrd2_idx]) return false;
            
            wrd1_idx ++,wrd2_idx ++;
            if(wrd1_idx == word1[wrd1].length()){wrd1_idx = 0;wrd1++;}
            if(wrd2_idx == word2[wrd2].length()){wrd2_idx = 0;wrd2++;}
        }
        if(wrd1 == word1.size() && wrd2 == word2.size())
            return true;
        return false;
    }
};