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
    void solve(TreeNode* root,int& H,int h,int& sum){
        if(root->left == nullptr && root->right == nullptr){
            
            if(H<h)
            {
                H = h;
                sum = root->val;
                
            }else if( H == h){
                sum += root->val;
            }
            // cout<<H<<' '<<h<<' '<<sum<<' '<<root->val<<endl;
            return;
        }
        
        if(root->left)solve(root->left,H,h+1,sum);
        if(root->right)solve(root->right,H,h+1,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int H = 0;
        solve(root,H,0,sum);
        return sum;
    }
};