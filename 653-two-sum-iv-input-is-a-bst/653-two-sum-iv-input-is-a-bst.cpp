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
    
    void giveAllElement(TreeNode* root, vector<int>&vec){
        if(!root)return;
        vec.push_back(root->val);
        if(root->left)giveAllElement(root->left,vec);
        if(root->right)giveAllElement(root->right,vec);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> allele;
        giveAllElement(root,allele);
        sort(allele.begin(),allele.end());
        int n = allele.size();
        for(int i=0;i<n-1;i++){
            if(binary_search(allele.begin()+i+1,allele.end(),k-allele[i])) return true;
        }
        return false;
    }
};