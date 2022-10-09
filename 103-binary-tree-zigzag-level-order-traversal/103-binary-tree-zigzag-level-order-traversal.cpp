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
            int size = q.size();
            vector<int> level(size);
            for(int i = 0;i<size;i++){
                root = q.front();
                q.pop();
                
                int idx = flag ? i : size - 1 - i;
                level[idx] = root->val;
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};