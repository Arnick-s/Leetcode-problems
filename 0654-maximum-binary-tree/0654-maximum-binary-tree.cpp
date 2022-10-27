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
    void recursion(vector<int> & vec,int si,int ei,TreeNode*&root){
        
        if(si>ei){
            root = NULL;
            return;
        }
        int idx =  distance(vec.begin(),max_element(vec.begin()+si,vec.begin() + ei +1));
        root->val = vec[idx];
        root->left = new TreeNode();
        recursion(vec,si,idx-1,root->left);
        root->right = new TreeNode();
        recursion(vec,idx+1,ei,root->right);
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        recursion(nums,0,nums.size() -1,root);
        return root;
    }
};