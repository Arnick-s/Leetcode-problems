class Solution {
public:
    const int mod = 1e9+7;

    int sumSubarrayMins(vector<int>& arr) {
    
        int n = arr.size();
        vector<int> right_min(n),left_min;
        stack<int> st;
        
        //left min
        for(int i = 0;i<arr.size();i++){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                left_min.push_back(-1);
                st.push(i);
            }
            else{
                left_min.push_back(st.top());
                st.push(i);
            }
        }
        while(!st.empty())st.pop();
        
        //right min
        for(int i = arr.size() -1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                right_min[i] = n;
                st.push(i);
            }
            else{
                right_min[i] = st.top();
                st.push(i);
            }
        }
        
        long long res = 0;
        for(int i = 0;i<n;i++){
            
            long long l = i - left_min[i] ;
            long long r = right_min[i] - i ;
            
            res += (l * r)*arr[i];
            res%=mod;
        }
        
        return res;
    }
};
// <-left- me -right->
//we neet to cal all the ways possible for right and left 
// for right: a b c d;
// no of possible right sequence;
// ab, abc, abcd
// I need left min and right min
// stack next smaller ele 
// think for duplicates
