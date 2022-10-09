class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        int i1 = 0;
        int j1 = 0;
        int i2 = 0;
        int j2 = 0;
        
        while(i1<n1 && i2<n2){
            if(j1==word1[i1].size()){
                j1 = 0;
                i1++;
                continue;
            }
            if(j2==word2[i2].size()){
                j2 = 0;
                i2++;
                continue;
            }
            if(word1[i1][j1] == word2[i2][j2]){
                j1++;
                j2++;
            }
            else return false;
            
        }
        if(n1==i1 and j2 == word2[i2].size() && i2 == n2-1)return true;
        
        return false;
    }
};