class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto &it: s){
            if(st.empty() || st.top() != it) st.push(it);
            else{
                st.pop();
            }
        }
        int n = st.size();
        s.resize(n);
        int idx = n-1;
        while(!st.empty()){
            s[idx] = st.top();
            st.pop();
            idx--;
        }
        return s;
    }
};