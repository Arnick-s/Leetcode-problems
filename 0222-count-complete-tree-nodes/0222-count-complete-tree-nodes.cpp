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
    pair<int,int> solve(TreeNode* root){
        int lh = 0;
        TreeNode* copy = root;
        while(root!=NULL){
            root = root->left;
            lh++;
        }
        
        int rh = 0;
        while(copy!=NULL){
            copy = copy->right;
            rh++;
        }
        return {lh,rh};
    }
    int countNodes(TreeNode* root) {
        pair<int,int> h = solve(root);
        if(h.first == h.second){
            return pow(2,h.first) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};