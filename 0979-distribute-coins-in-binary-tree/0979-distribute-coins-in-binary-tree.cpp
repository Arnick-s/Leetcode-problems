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
    int distributeCoins(TreeNode* root,int&ans) {
        if(root == NULL)return 0;
        
        //post Order Traversal -> left right root
        int left = distributeCoins(root->left,ans);
        int right = distributeCoins(root->right,ans);
        // cout<<"root ->val = "<<root->val<<" left = "<<left<<" right = "<<right<<endl;
        ans += abs(root->val -1 + left + right);
        
        return (root->val -1 + left + right);
    }
    
    int distributeCoins(TreeNode* root){
        if(!root)return 0;
        int ans = 0;
        distributeCoins(root,ans);
        return ans;
    }
};
//we need to start from leaf then parent
