class Solution {
public:
    vector<vector<int>> memo;
    int dfs(vector<int> &nums,int prev,int curr) {
        if(curr>=nums.size()) return 0;

        if(memo[prev+1][curr]!=-1) return memo[prev+1][curr];

        int res=dfs(nums,prev,curr+1);

        if(prev==-1 || nums[prev]<nums[curr]) {
            res=max(res,1+dfs(nums,curr,curr+1));
        }

        return memo[prev+1][curr]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size()+1,vector<int> (nums.size(),-1));
        return dfs(nums,-1,0);
    }
};