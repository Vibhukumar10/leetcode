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
        vector<vector<int>> v;
        if(!root) return v;
        
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                TreeNode *temp=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();
                
                mp[x][y].insert(temp->val);
                
                if(temp->left) q.push({temp->left,{x-1,y+1}});
                if(temp->right) q.push({temp->right,{x+1,y+1}});
            }
        }
        
        for(auto it:mp) {
            vector<int> add;
            for(auto itr:it.second) {
                for(auto itrr:itr.second) {
                    add.push_back(itrr);
                }
            }
            v.push_back(add);
        }
        
        return v;
    }
};