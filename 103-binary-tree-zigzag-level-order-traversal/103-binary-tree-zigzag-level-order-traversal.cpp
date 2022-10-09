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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        bool flag = true;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            while(size--){
                root = q.front();
                q.pop();
                level.push_back(root->val);
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            if(flag)
            {
                flag = false;
            }
            else{
                reverse(level.begin(),level.end());
                flag = true;
            }
                ans.push_back(level);
        }
        return ans;
    }
};