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
    
    pair<int,int> binary_search(vector<int>&nums,int target,int l,int r){
        l--;
        r++;
        while(r-l>1){
            int m = l + (r-l)/2;
            
            if(nums[m]>=target) r=m;
            else l = m;
        }
        return {l,r};
    }
    void recursion(TreeNode*& root,vector<int>&vec,int si,int ei){
        
        if(ei<si){
            root = NULL;
            return;
        }
        root->val = vec[si];
        if(si == ei)return;
        pair<int,int> lr = binary_search(vec,root->val,si+1,ei);
        root->left = new TreeNode();
        root->right = new TreeNode();
        
        recursion(root->left,vec,si+1,lr.first);
        recursion(root->right,vec,lr.second,ei);
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode();
        recursion(root,preorder,0,preorder.size()-1);
        return root;
    }
};