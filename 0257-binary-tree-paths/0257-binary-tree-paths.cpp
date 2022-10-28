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
    void recursion(TreeNode* root,vector<string>&res,string s){
        if(!root){
            return;
        }else if(root->right == NULL && root->left == NULL){
            res.push_back(s + to_string(root->val));
        }
        if(root->left) recursion(root->left,res,s + to_string(root->val)+"->");
        
        if(root->right) recursion(root->right,res,s + to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        recursion(root,res,"");
        return res;
    }
};