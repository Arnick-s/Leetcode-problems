class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hash;
        
        for(int i = 0;i<words.size();i++){
            hash[words[i]]++;
        }
        vector<string> res(k);
        for(int i = 0;i<k;i++){
            string maxS = hash.begin()->first;
            auto maxFreqIt = hash.begin();
            for(auto it = hash.begin();it != hash.end();it++){
                if(it->second > maxFreqIt->second){
                    maxS = it->first;
                    maxFreqIt = it;
                }else if(it->second == maxFreqIt->second && it->first < maxFreqIt->first){
                    maxS = it->first;
                    maxFreqIt = it;
                }
            }
            cout<<maxFreqIt->first<<endl;
            maxFreqIt->second = 0;
            res[i] = maxS;
        }
        return res;
    }
};