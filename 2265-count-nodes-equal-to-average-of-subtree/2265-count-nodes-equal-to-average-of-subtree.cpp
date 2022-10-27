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
    
    pair<int,int> solve(TreeNode* root,int& ans){
        if(!root) return {0,0};
        pair<int,int> left = solve(root->left,ans);
        pair<int,int> right = solve(root->right,ans);
        
        int sum  = left.first + root->val + right.first;
        if(sum/(left.second +  1 + right.second) == root->val) ans++;
        return {sum,left.second + 1 + right.second};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};