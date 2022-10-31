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
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* head = root;
        queue<TreeNode*> q;
        q.push(root);
        
        bool odd = true;
        while(!q.empty()){
            odd = !odd;
            int size = q.size();
            vector<TreeNode*> level;
            while(size--){
                root = q.front();
                q.pop();
                if(odd){
                    level.push_back(root);
                }
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
            
            if(odd){
                int n = level.size();
                for(int i = 0;i<n/2;i++){
                    swap(level[i]->val,level[n-1 -i]->val);
                }
            }
        }
        return head;
    }
};