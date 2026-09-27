class Solution {
public:
    map<pair<int,int>,int> memo;
    int dfs(vector<int> &nums, int idx, int target) {
        if(idx==nums.size()) {
            return target==0;
        }  

        if(memo.find({target,idx})!=memo.end()) {
            return memo[{target,idx}];
        }

        int plus=dfs(nums,idx+1,target-nums[idx]);
        int minus=dfs(nums,idx+1,target+nums[idx]);
        
        return memo[{target,idx}]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,0,target);
    }
};