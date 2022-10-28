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
    bool isUnivalTree(TreeNode* root) {
        
        int val = root->val;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            root = st.top();
            st.pop();
            if(root->val != val) return false;
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        return true;
    }
};