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
    int sum(TreeNode* &root){
        if(root == NULL)return 0;
        
        root->val += (sum(root->right) + sum(root->left));
        return root->val;
    }
    
    void abc(TreeNode* root,int & ans){
        if(!root) return;
        int l = 0;
        int r = 0;
        if(root->left){
            l = root->left->val;
            abc(root->left,ans);
        }if(root->right){
            
            r = root->right->val;
            abc(root->right,ans);
        }
        
        ans += abs(l-r);
    }
    int findTilt(TreeNode* root) {
        TreeNode* copy = root;
        sum(copy);
        
        int ans = 0;
        abc(root,ans);
        return ans;
    }
};