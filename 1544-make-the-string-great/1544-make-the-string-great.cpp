class Solution {
public:
    
    string makeGood(string s) {
        stack<char> st;
        // auto check = [](char& a,char& b)->bool
        //         {
        //             return abs(a - b) == 32;
        //         };
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }else{
                char a = st.top();
                char b = s[i];
                if([&]{
                    return abs(a-b) == 32;
                }())
                {
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
            
        }
        //ans;
        n = st.size();
        s.resize(n);
        for(int i = 0;i<n;i++){
            s[n-1 - i] = st.top();
            st.pop();
        }
        return s;
    }
};