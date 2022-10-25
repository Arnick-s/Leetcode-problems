class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &vec:image)
            reverse(vec.begin(),vec.end());
        
        for(auto &vec:image)
            for(auto &it:vec)
            {
                if(it == 0)it = 1;
                else it = 0;
            }
        return image;
    }
};