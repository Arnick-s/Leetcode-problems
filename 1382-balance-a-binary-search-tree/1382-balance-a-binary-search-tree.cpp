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
    void inorder(TreeNode* root,vector<int>&nums){
        if(!root) return;
        
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    
    void construct_tree(TreeNode*& root,vector<int>&nums,int si,int ei){
        if(ei<si){
            root = NULL;
            return;
        }
        
        int m = si + (ei - si)/2;
        root->val = nums[m];

        root->left = new TreeNode();
        root->right = new TreeNode();
        
        construct_tree(root->left,nums,si,m-1);
        construct_tree(root->right,nums,m+1,ei);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        
        root = new TreeNode();
        construct_tree(root,nums,0,nums.size()-1);
        
        return root;
    }
};