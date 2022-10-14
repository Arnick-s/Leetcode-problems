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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2){
            return root1?:root2;
        }
        if(root1->left == NULL || root1->right == NULL){
            if(!(root1->left or root1->right)){
                root1->val += root2->val;
                root1->left = root2->left;
                root1->right = root2->right;
                return root1;
            }else if(!root1->left){
                root1->val += root2->val;
                root1->left = root2->left;
                mergeTrees(root1->right,root2->right);
                return root1;
            }else{
                root1->val += root2->val;
                root1->right = root2->right;
                mergeTrees(root1->left,root2->left);
                return root1;
            }
        }        
        root1->val  += root2->val;
        mergeTrees(root1->left,root2->left);
        mergeTrees(root1->right,root2->right);
        return root1;
    }
};