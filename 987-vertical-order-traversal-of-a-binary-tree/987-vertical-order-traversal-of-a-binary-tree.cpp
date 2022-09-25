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
        vector<vector<int>> res;
        map<int,vector<pair<int,int>>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        int l=1;
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                TreeNode *temp=q.front().first;
                int level=q.front().second;
                q.pop();
                
                mp[level].push_back({l,temp->val});
                
                if(temp->left) q.push({temp->left,level-1});
                if(temp->right) q.push({temp->right,level+1});
            }
            l++;
        }
        
        for(auto it:mp) {
            vector<pair<int,int>> ans=it.second;
            sort(ans.begin(),ans.end());
            // for(auto i:ans) {
            //     cout<<i.first<<" "<<i.second<<endl;
            // }
            vector<int> add;
            for(int i=0;i<ans.size();i++) {
                add.push_back(ans[i].second);
            }
            res.push_back(add);
        }
        
        return res;
    }
};