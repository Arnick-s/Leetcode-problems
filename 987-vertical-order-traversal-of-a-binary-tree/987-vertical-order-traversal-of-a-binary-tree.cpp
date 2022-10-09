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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        //using map because 1)we need things in sorted order when
        //when nodes are at same position
        //2) we dont know how many items are there
        //3) from top to bottom - if we assign every level a value(increasing while going down) then we have to return in sorted order of that value
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                root = q.front().first;
                //x and y axis of that node
                int x = q.front().second.first;
                int y = q.front().second.second;
                
                q.pop();
                
                mp[x][y].insert(root->val);
                
                if(root->left)  q.push({root->left,{x-1,y+1}});
                if(root->right) q.push({root->right,{x+1,y+1}});
            }
        }
        
        for(auto it:mp){
            vector<int> col;
            for(auto ii:it.second){
                // col.insert(col.end(),ii.second.begin(),ii.second.end());
                for(auto ij:ii.second){
                    col.push_back(ij);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};