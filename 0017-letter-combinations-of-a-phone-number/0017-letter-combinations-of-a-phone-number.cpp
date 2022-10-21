class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)return {};
        vector<string> keypad(10,"");
        keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.length();
        vector<string> ans;
        for(int i = 0;n>=1 && i<keypad[digits[0]-'0'].length();i++){
            string temp = "";
            temp += keypad[digits[0]-'0'][i];
            for(int j = 0;n>=2 && j<keypad[digits[1]-'0'].length();j++){
                string temp1 = temp + keypad[digits[1]-'0'][j];
                for(int k = 0;n>=3 && k<keypad[digits[2]-'0'].length();k++){
                    string temp2 = temp1 + keypad[digits[2]-'0'][k];
                    for(int l = 0;n>=4 && l<keypad[digits[3]-'0'].length();l++){
                        ans.push_back(temp2 + keypad[digits[3]-'0'][l]);
                    }
                    if(n<4){
                        ans.push_back(temp2);
                    }
                }
                if(n<3)
                    ans.push_back(temp1);
            }
            if(n<2)
                ans.push_back(temp);
        }
        return ans;
    }
};