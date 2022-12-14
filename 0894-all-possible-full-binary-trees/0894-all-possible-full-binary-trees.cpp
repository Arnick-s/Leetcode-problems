
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
    
    vector<TreeNode*> helper(int n){
        
        if(n == 1){
            return {new TreeNode(0)};
        }
        vector<TreeNode*> res;
        
        for(int i = 1;i<n;i+=2){
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n-1-i);
            
            for(auto l : left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(0,l,r);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};