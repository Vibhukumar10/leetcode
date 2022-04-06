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
    unordered_set<TreeNode*> st;
    unordered_map<string,TreeNode*> mp;
    
    string traverse(TreeNode *root) {
        if(!root) return "";
        
        string left=traverse(root->left);
        string right=traverse(root->right);
        string curr=left+" "+right+" "+to_string(root->val);
        
        if(mp.find(curr)!=mp.end()) {
            st.insert(mp[curr]);
        } else {
            mp[curr]=root;
        }
        
        return curr;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        traverse(root);
        for(auto it:st) {
            res.push_back(it);
        }
        
        return res;
    }
};