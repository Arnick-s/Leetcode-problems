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
    void inorderTraversal(TreeNode* root,vector<TreeNode*>&inord){
        if(!root) return;
        
        inorderTraversal(root->left,inord);
        inord.push_back(root);
        inorderTraversal(root->right,inord);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return nullptr;
        vector<TreeNode*> inord;
        
        inorderTraversal(root,inord);//vector with nodes with inorder fashion
        int n = inord.size();
        
        for(int i = 0 ;i < n-1 ;i++){
            inord[i]->right = inord[i+1];
            inord[i]->left = NULL;
        }
        inord[n-1]->right = NULL;
        inord[n-1]->left = NULL;
        
        return inord[0];
    }
};