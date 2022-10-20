/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//1) parent of every pointer
//2) I need to find the target node address
//3) move radially 
//4) return the queue

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent_rec;
        // parent_rec[root] = NULL;
            
        //BFS Traversal
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0;i<q_size;i++){
                root = q.front();
                q.pop();
                if(root->left){
                    q.push(root->left);
                    parent_rec[root->left] = root;
                }
                if(root->right){
                    q.push(root->right);
                    parent_rec[root->right] = root;
                }
            }
        }
        //now we have parent record for every node
        //as we already have our target node so we do not need to find it
        //now we have to go outward radially from the target node;
        
        set<TreeNode*> seen_Already;
        queue<TreeNode*> q_Radial;
        
        q_Radial.push(target);
        seen_Already.insert(target);
        while(k){
            k--;
            int q_size = q_Radial.size();
            while(q_size--){
                root = q_Radial.front();
                q_Radial.pop();
                if(root->left && seen_Already.find(root->left) == seen_Already.end()){
                    q_Radial.push(root->left);
                    seen_Already.insert(root->left);
                }
                if(root->right && seen_Already.find(root->right) == seen_Already.end()){
                    q_Radial.push(root->right) ;
                    seen_Already.insert(root->right);
                }
                auto it = parent_rec.find(root);
                if(it != parent_rec.end() && seen_Already.find(it->second) == seen_Already.end()){
                    q_Radial.push(it->second);
                    seen_Already.insert(it->second);
                }
                
            }
        }
        
        vector<int> res;
        while(!q_Radial.empty()){
            res.push_back(q_Radial.front()->val);
            q_Radial.pop();
        }
        return res;
    }
};