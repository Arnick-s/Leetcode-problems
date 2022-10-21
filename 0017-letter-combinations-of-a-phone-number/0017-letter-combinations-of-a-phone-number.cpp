class Solution {
public:
    const vector<string> pad = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digit) {
        if(digit.length()==0)return {};
        vector<string>ans;
        f(0,digit,ans,""); 
        return ans;
    }
    void f(int idx,string &digit,vector<string>&ans,string s){
        if(idx==digit.length())ans.push_back(s);
        else for(auto c : pad[digit[idx]-'0'])f(idx+1,digit,ans,s+c); 
    }
};