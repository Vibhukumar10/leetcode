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
    pair<int,int> dfs(TreeNode *root,int &count) {
        if(!root) {
            return {0,0};
        }
        
        if(!root->left && !root->right) {
            count++;
            return {root->val,1};
        }

        pair<int,int> lTree=dfs(root->left,count);
        pair<int,int> rTree=dfs(root->right,count);

        int sum=lTree.first+rTree.first+root->val;
        int nodes=lTree.second+rTree.second+1;

        if(sum/nodes==root->val) {
            count++;
        }

        return {sum,nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int count=0;
        pair<int,int> p=dfs(root,count);
        return count;
    }
};