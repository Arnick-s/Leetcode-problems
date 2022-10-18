class Solution {
public:
    bool isPerfectSquare(int N) {
        if(N==1)return true;
        int l = 0, r = N/2;
        long long m;
        
        while(l<=r){
            m = l + (r-l)/2;
            long long m_sq = m*m;
            if(m_sq == N) return true;
            else if(m_sq < N) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
};