/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* visited(int val,unordered_map<int,TreeNode*>&ump){
        auto it = ump.find(val);
        if(it == ump.end()){
            TreeNode* node = new TreeNode(val);
            ump[val] = node;
            return node;
        }else{
            return it->second;
        }
        return nullptr;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,TreeNode*> ump;
        unordered_map<TreeNode*,TreeNode*> parent;
        for(auto &it: des){
            
            TreeNode* p = visited(it[0],ump);
            TreeNode* c = visited(it[1],ump);
            
            parent[c] = p;
            if(it[2]){
                p->left = c;
            }else{
                p->right = c;
            }
        }
        auto ii = ump.find(des[0][0]);
        auto it = parent.find(ii->second); 
        auto prev = ii->second;
        
        while(it!=parent.end()){
            prev = it->second;
            it = parent.find(it->second);
        }
        
        return prev;
    }
};