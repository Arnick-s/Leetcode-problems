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
    
    void solve(TreeNode* root,int&ans){
        if(!root)return;
        if(root->val%2 == 0){
            if(root->left){
                if(root->left->left)
                    ans+=root->left->left->val;
                if(root->left->right)
                    ans+=root->left->right->val;
                
                solve(root->left,ans);
            }
            if(root->right){
                if(root->right->left)
                    ans+=root->right->left->val;
                if(root->right->right)
                    ans+=root->right->right->val;
                
                solve(root->right,ans);
            }
            return;
        }
        
        if(root->left) solve(root->left,ans);
        if(root->right) solve(root->right,ans);
        
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return sum;
    }
};