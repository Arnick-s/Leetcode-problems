class Solution {
public:
    int countPoints(string rings) {
        
        vector<bool> red(101,false);
        vector<bool> green(101,false);
        vector<bool> blue(101,false);
        
        int n = rings.length();
        for(int i = 0;i<n;i+=2){
            if(rings[i] == 'R')red[rings[i+1]] = true;
            if(rings[i] == 'G')green[rings[i+1]] = true;
            if(rings[i] == 'B')blue[rings[i+1]] = true;
        }
        int res = 0;
        for(int i = 0;i<=100;i++){
            if(red[i]&&green[i]&&blue[i])res++;
        }
        return res;
    }
};