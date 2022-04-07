/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_set<TreeNode*> seen;
    void printK(TreeNode *root,TreeNode *target,int k,vector<int> &res) {
        cout<<k<<" ";
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                TreeNode *temp=q.front().first;
                int dist=q.front().second;
                q.pop();
                
                
                if(dist==k && seen.find(temp)==seen.end()) {
                    res.push_back(temp->val);
                }
                
                seen.insert(temp);
                
                if(temp->left) q.push({temp->left,dist+1});
                if(temp->right) q.push({temp->right,dist+1});
            }
        }
    }
    
    bool getPath(TreeNode *root, TreeNode *node,vector<TreeNode*> &path) {
        if(!root) return false;
        
        path.push_back(root);
        if(root==node) return true;
        if(getPath(root->left,node,path) || getPath(root->right,node,path))
            return true;
            
        path.pop_back();
        return false;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(!root) return res;
        if(k==0) {
            res.push_back(target->val);
            return res;
        }
        
        vector<TreeNode*> path;
        getPath(root,target,path);
        
        // seen.insert(target);
        // for(int i=0;i<path.size();i++) {
        //     seen.insert(path[i]);
        // }
        
        int i=path.size()-1;
        while(i>=0) {
            printK(path[i],target,k,res);
            // seen.insert(path[i]);
            k--;
            i--;
            if(k<-1) {
                break;
            }
        }
        
        return res;
    }
};