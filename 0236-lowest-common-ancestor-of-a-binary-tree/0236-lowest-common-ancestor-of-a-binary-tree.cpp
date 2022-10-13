/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool rootNodePath(TreeNode* root,TreeNode* node,vector<TreeNode*>&nums){
        if(root == NULL) return false;
        
        nums.push_back(root);
        if(node == root) return true;
        if(rootNodePath(root->left,node,nums) || rootNodePath(root->right,node,nums))
            return true;
        
        nums.pop_back();
        return false;
    }
    void printvec(vector<TreeNode*>&nums){
        for(auto &it:nums)cout<<it->val<<" ";
        cout<<endl;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecp,vecq;
        rootNodePath(root,p,vecp);
        rootNodePath(root,q,vecq);
        
        int n = min(vecq.size(),vecp.size());
        
        TreeNode* ans;
        for(int i = 0;i<n;i++){
            if(vecq[i]==vecp[i]){
                ans = vecq[i];
            }else{
                break;
            }
        }
        return ans;
    }
};