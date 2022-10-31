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

        while(!q.empty()){
            int size = q.size();
            bool flagx = false,flagy = false;

            while(size--){
                root = q.front();
                q.pop();
                if(root->val == x){
                    flagx = true;
                }
                if(root->val == y){
                    flagy = true;
                }
                if(root->left && root->right){
                    int l = root->left->val;
                    int r = root->right->val;
                    
                    if(max(x,y) == max(l,r) && min(x,y) == min(l,r))
                        return false;
                }
                if(root->left) {
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
            if(flagx && flagy) return true;
        }
        return false;
    }
};