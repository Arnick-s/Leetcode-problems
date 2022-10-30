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
    void recursion(TreeNode* root, vector<int>&nums){
        if(!root) return ;
        
        recursion(root->left,nums);
        nums.push_back(root->val);
        recursion(root->right,nums);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        recursion(root,nums);
        
        int mini = INT_MAX;
        for(int i = 1;i<nums.size();i++){
            mini = min(mini,nums[i]-nums[i-1]);
        }
        return mini;
    }
};