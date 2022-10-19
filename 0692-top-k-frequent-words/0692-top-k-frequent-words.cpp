class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hash;
        
        for(int i = 0;i<words.size();i++){
            hash[words[i]]++;
        }
        vector<string> res(k);
        for(int i = 0;i<k;i++){
            auto maxFreqIt = hash.begin();
            for(auto it = hash.begin();it != hash.end();it++){
                if(it->second > maxFreqIt->second){
                    maxFreqIt = it;
                }else if(it->second == maxFreqIt->second && it->first < maxFreqIt->first){
                    maxFreqIt = it;
                }
            }
            maxFreqIt->second = 0;
            res[i] = maxFreqIt->first;
        }
        return res;
    }
};