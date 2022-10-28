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
    string tree2str(TreeNode* root) {
        cout<<(root == NULL)<<endl;
        if(!root) return "()";
        
        string s = to_string(root->val);
        string s1 = tree2str(root->left);
        string s2 = tree2str(root->right);
        
        if(s2 == "()"){
            if(!(s1 == "()")){
                s += "(" + s1 + ")";
            }   
        }else{
            if(s1 == "()")s1 = "";
            s += "(" + s1 + ")" + "(" + s2 + ")";
        }
        return s;
    }
};