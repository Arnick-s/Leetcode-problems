class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        vector<pair<char,int>> vpic(257,{'*',0});
        
        for(int i = 0;i<n;i++){
            vpic[s[i]].first = s[i];
            vpic[s[i]].second++;
        }
        
        sort(vpic.begin(),vpic.end(),[](pair<char,int>&a,pair<char,int>&b){
            return a.second > b.second;
        });
        
        string res = "";
        for(auto&p:vpic){
            if(p.first == '*')break;
            
            int t = p.second;
            char a = p.first;
            while(t--)
                res+=a;
        }
        return res;
    }
};