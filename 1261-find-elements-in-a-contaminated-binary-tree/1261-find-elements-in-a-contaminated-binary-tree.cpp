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
class FindElements {
public:
    TreeNode* head;
    vector<int> ele;
    FindElements(TreeNode* root) {
        head = root;
        //bfs
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                
                root = q.front();
                q.pop();
                ele.push_back(root->val);
                if(root->left) {
                    root->left->val = root->val*2 + 1;
                    q.push(root->left);
                }
                if(root->right) {
                    root->right->val = root->val*2 + 2;
                    q.push(root->right);
                }
            }
        }
        
    }
    
    bool find(int target) {
        int r = ele.size()-1;
        int l = 0;
        while(l<=r){
            int m = l + (r-l)/2;
            if(ele[m] == target)return true;
            else if(ele[m]<target)l = m+1;
            else r = m-1;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */