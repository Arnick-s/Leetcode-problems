class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &vec: image){
            int n = vec.size();
            for(int i = 0;i<(n+1)/2;i++){
                int temp = vec[i];
                vec[i] = (vec[n-1 -i] == 0) ? 1 : 0;
                vec[n-1 -i] = (temp == 0) ? 1 : 0;
            }
        }
        return image;
    }
};