class Solution {
public:
    long long get_whole_int(string&s,int &idx){
            long long res = 0;
            int n = s.length();
            while(idx<n && s[idx]>='0' && s[idx]<='9'){
                    res = res*10 + s[idx]-'0';
                    idx++;
            }
            
            return res;
    }
    int calculate(string s) {
            char prev = (s[0]!='-'?'+':'-');
            long long ans = 0;
            int n = s.length();
            stack<char> st;
            st.push('+');
        for(int i = 0;i<n;i++){

                if(s[i] == ' ')continue;
                
                if(s[i] == '('){
                        if(i == 0){
                                st.push('+');
                        }
                        
                        if(st.top() == '-'){
                                if(prev == '+')
                                st.push('-');
                                else st.push('+');
                        }else{
                                st.push(prev);
                        }
                        prev = '+';
                        continue;
                        
                }else if(s[i] == ')'){
                        
                        st.pop();
                        prev = '+';
                        continue;
                }

                char newPrev = (prev == st.top())?'+':'-';
                if(newPrev == '+'){
                        
                        long long a = get_whole_int(s,i);
                        ans += a;
                        if(i == n)break;
                        
                }else if(newPrev == '-'){
                        long long a = get_whole_int(s,i);
                        ans -= a;
                        if(i == n)break;
                }
                
                if(s[i] == ')'){
                        
                        st.pop();
                        prev = '+';
                        continue;
                }
                // cout<<"st.top = "<<st.top()<<"  st.size() ="<<st.size()<<endl;
                // cout<<"ans = "<<ans<<endl;
                prev = s[i];
        }
        return ans;
    }
};

//what I have to handle
// - (x,y,z)
// 32-bit integer -> done
