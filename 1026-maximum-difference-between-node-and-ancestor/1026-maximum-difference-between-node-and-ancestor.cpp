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
    
    pair<int,int> maxDiff(TreeNode* root, int &ans){
        if(!root->left && !root->right){
            return pair<int,int>(root->val,root->val);
        }else if(!root->left){
            pair<int,int> a = maxDiff(root->right,ans);
            ans = max(ans,max(abs(a.first - root->val),abs(a.second - root->val)));
            return pair<int,int>(max(a.first,root->val),min(a.second,root->val));
        }else if(!root->right){
            pair<int,int> a = maxDiff(root->left,ans);
            ans = max(ans,max(abs(a.first - root->val),abs(a.second - root->val)));
            return pair<int,int>(max(a.first,root->val),min(a.second,root->val));
        }
        
        pair<int,int> left = maxDiff(root->left,ans);
        pair<int,int> right = maxDiff(root->right,ans);
        
        int a = max(left.first,right.first),b = min(left.second,right.second) ;
        
        ans = max(ans,max(abs(a-root->val),abs(b-root->val)));
        
        return pair<int,int>(max(a,root->val),min(root->val,b));
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        if(root == NULL)return 0;
        maxDiff(root,ans);
        return ans;
    }
};