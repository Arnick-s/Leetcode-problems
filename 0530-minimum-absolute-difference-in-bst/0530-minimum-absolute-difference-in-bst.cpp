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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            
            nums.push_back(root->val);
            if(root->right)
                st.push(root->right);
            if(root->left)
                st.push(root->left);
        }
        
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        for(int i = 1;i<nums.size();i++){
            mini = min(mini,nums[i]-nums[i-1]);
        }
        
        return mini;
        
    }
};