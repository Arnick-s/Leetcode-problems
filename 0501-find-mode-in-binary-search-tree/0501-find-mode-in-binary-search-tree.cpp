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
    vector<int> findMode(TreeNode* root) {
        map<int,int> freq;
        
        stack<TreeNode*> st;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    freq[st.top()->val]++;
                    temp = st.top();st.pop();
                    while(!st.empty() && st.top()->right == temp){
                        temp = st.top();
                        st.pop();
                        freq[temp->val]++;
                    }
                }else{
                    root = temp;
                }
                
            }
        }
        vector<int> res;
        int maxi = 0;
        for(auto &it:freq){
            if(it.second>maxi){
                res.clear();
                res.emplace_back(it.first);
                maxi = it.second;
            }else if(it.second == maxi){
                res.emplace_back(it.first);
            }
        }
        return res;
    }
};