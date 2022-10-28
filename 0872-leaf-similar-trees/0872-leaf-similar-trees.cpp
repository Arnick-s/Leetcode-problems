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
    void give_leaves(TreeNode* root, vector<int>& vec){
        if(!root) return;
        else if(root->left == root->right){
            vec.push_back(root->val);
            return;
        }
        give_leaves(root->left,vec);
        give_leaves(root->right,vec);
        return;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        give_leaves(root1,first);
        vector<int> second;
        give_leaves(root2,second);
        
        return first == second;
    }
};