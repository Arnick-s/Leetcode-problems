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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        map<int,TreeNode*> parent;
        while(!q.empty()){
            int size = q.size();
            bool flagx = false,flagy = false;
            TreeNode* xp;
            TreeNode* yp;
            while(size--){
                root = q.front();
                q.pop();
                if(root->val == x){
                    flagx = true;
                    xp = parent[root->val];
                }
                if(root->val == y){
                    flagy = true;
                    yp = parent[root->val];
                }
                
                if(root->left) {
                    q.push(root->left);
                    parent[root->left->val] = root;
                }
                if(root->right){
                    q.push(root->right);
                    parent[root->right->val] = root;
                }
            }
            if(flagx && flagy && xp!=yp) return true;
        }
        return false;
    }
};