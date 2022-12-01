class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        //stack + last index + 1 parsing
        unordered_map<char,int> last_idx;
        vector<bool> seen(26,false);
        
        int n = s.length();
        for(int i = 0;i<n;i++){
            last_idx[s[i]] = i;
        }
        
        stack<char> st;st.push(s[0]);
        seen[s[0] - 'a'] = true;
        
        for(int i = 1;i<n;i++){
            if(seen[s[i] - 'a'] == true)continue;
            
            if(st.top()<s[i])
                st.push(s[i]);
            
            else{
                
                while(!st.empty() && last_idx[st.top()]>i && st.top() >= s[i]){
                    seen[st.top() - 'a'] = false;
                    st.pop();
                }
                
                st.push(s[i]);
            }
            seen[s[i] - 'a'] = true;
        }
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};