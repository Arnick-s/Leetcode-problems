class Solution {
public:
    
    void printst(stack<int> st){
        cout<<"Stack = ";
        while(!st.empty()){
            cout<<st.top()<<' ';
            st.pop();
        }cout<<endl;
    }
    
    bool is_compatible(string s1,string& s2){
        if(s1.length() == 0 || s2.length() == 0) return true;
        sort(s1.begin(),s1.end());
        //searching s2 ele in s1
        
        for(auto &target:s2){
            int l = 0;
            int r = s1.length();
            
            while(l<=r){
                int mid = l + (r-l)/2;
                if(target == s1[mid]) return false;
                else if( target > s1[mid] ) l = mid + 1;
                else r = mid - 1;
            }
            
        }
        return true;
    }
    
    bool is_unique(string&s){
        vector<int> hash(26,0);
        for(auto &it:s){
            if(hash[it - 'a'] == 0)hash[it - 'a']++;
            else return false;
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        
        stack<int> st;
        int n = arr.size();
        int maxi = 0;
        // I will start with index 0;
        st.push(0);
        
        string s = "";
        
        while(!st.empty()){
            //validation of the st top;
            if(st.top() >= n || !is_unique(arr[st.top()])){
                if(st.top() >= n){
                    
                    st.pop();
                    if(st.empty()) return maxi;
                    
                    int top = st.top();
                    st.pop();
                    st.push(top+1);
                    //update st
                    s = s.substr(0,(int)s.length() - (int)arr[top].length());
                    
                    continue;
                } 
                else{
                    int top = st.top();
                    st.pop();
                    st.push(top+1);
                    continue;
                }
            }//we have checked the validity
            //we need to add another string
 
            if(!is_compatible(s,arr[st.top()])){
                int top = st.top();
                st.pop();
                st.push(top + 1);
                continue;
            }else{
                s += arr[st.top()];
                maxi = max(maxi,(int)s.length());
                st.push(st.top() + 1);
                continue;
            }
        }
        return maxi;
    }
};