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
    void fun(stack<TreeNode*> &st,TreeNode* &root){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1,st2;
        TreeNode* r1 = root1;
        TreeNode* r2 = root2;
        vector<int> res;
        fun(st1,r1);fun(st2,r2);
        while((!st1.empty()||r1) && (!st2.empty()||r2)){
            r1 = st1.top();
            r2 = st2.top();
            
            if(r1->val <= r2->val){
                res.push_back(r1->val);
                st1.pop();
                r1 = r1->right;
                fun(st1,r1);
            }else{
                res.push_back(r2->val);
                st2.pop();
                r2 = r2->right;
                fun(st2,r2);
            }
        }
        
        while(!st1.empty() || r1){
            r1 = st1.top();
            st1.pop();
            res.push_back(r1->val);
            r1 = r1->right;
            fun(st1,r1);
        }
        while(!st2.empty()|| r2){
            r2 = st2.top();
            st2.pop();
            res.push_back(r2->val);
            r2 = r2->right;
            fun(st2,r2);
        }
        return res;
    }
};