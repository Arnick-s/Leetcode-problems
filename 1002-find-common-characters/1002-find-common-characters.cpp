class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        
        vector<pair<bool,int>>common_hash(27,pair<bool,int>(false,0));
        for(int i = 0;i<words[0].length();i++){
            common_hash[words[0][i] - 'a'].first = true;
            common_hash[words[0][i] - 'a'].second ++;
        }
        
        for(int word = 1;word<n;word++){
            int m = words[word].length();
            vector<int> hash(27,0);
                for(int i = 0;i<m;i++){
                    hash[words[word][i] - 'a']++;
                }
            //updating common
            for(int i = 0;i<27;i++){
                if(hash[i] == 0)common_hash[i].first = false;
                else if(hash[i]>0){
                    common_hash[i].second = min(common_hash[i].second,hash[i]);
                }
            }
        }
        vector<string> ans;
        for(int i = 0;i<27;i++){
            if(common_hash[i].first){
                for(int j = 0;j<common_hash[i].second;j++){
                    string s = "";
                    s.push_back(i+'a');
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};