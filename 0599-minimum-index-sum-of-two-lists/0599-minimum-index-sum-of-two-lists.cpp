class Solution {
public:
    #define All(x) x.begin(),x.end()
    #define SZ(X) X.size()
    typedef int I;
    typedef vector<string> VS;
    #define IM INT_MAX
    #define pb(X) push_back(X);
    
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        VS res;
        I n = SZ(list1);
        I m = SZ(list2);
        
        I idx1 = 0;
        I idx2 = 0;
        
        I idxsum = IM;
        while(idx1<n){
            
            while(idx2<m && idx1<n){
                // cout<<idx1<<' '<<idx2<<endl;
                if(list1[idx1] == list2[idx2]){
                    if(idxsum == idx1 + idx2){
                        res.pb(list1[idx1]);
                        idx2=0;
                        idx1++;
                    }else if(idxsum > idx1 + idx2){
                        res.clear();
                        res.pb(list1[idx1]);
                        idxsum = idx1 + idx2;
                        idx1++;
                        idx2 = 0;
                    }else{
                        idx2++;
                    }
                }else if(idxsum >= idx1 + idx2){
                    idx2++;
                }else{
                    idx1++;
                    idx2 = 0;
                }
                // cout<<idx1<<' '<<idx2<<endl;
            }
            if(idx2 == m){
                idx2 = 0;
                idx1 ++;
            }
        }
        return res;
    }
};