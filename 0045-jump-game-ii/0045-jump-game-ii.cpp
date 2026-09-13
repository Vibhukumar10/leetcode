class Solution {
public:
    unordered_map<int,int> memo;
    int dfs(vector<int> &nums,int idx) {
        if(idx>=nums.size()-1) {
            return 0;
        }

        if(memo.find(idx)!=memo.end()) return memo[idx];

        int maxJump=nums[idx];
        int minJump=INT_MAX;

        for(int jump=1;jump<=maxJump;jump++) {
            int result = dfs(nums, idx + jump);
            if(result != INT_MAX) {
                minJump = min(minJump, 1 + result);
            }
        }

        return memo[idx]=minJump;
    }
    int jump(vector<int>& nums) {
        return dfs(nums,0);
    }
};