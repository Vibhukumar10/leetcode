class Solution {
public:
    unordered_map<int,int> memo;
    int dfs(vector<int> &nums,int target) {
        if(target==0) {
            return 1;
        }

        if(memo.find(target)!=memo.end()) {
            return memo[target];
        }

        int count=0;
        for(int num:nums) {
            if(target-num>=0) {
                count+=dfs(nums,target-num);
            }
        }

        return memo[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums,target);
    }
};