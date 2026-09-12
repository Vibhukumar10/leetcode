class Solution {
public:
    unordered_map<int,bool> memo;
    bool dfs(vector<int> &nums,int i) {
        if(i==nums.size()-1) {
            return true;
        }

        if(memo.find(i)!=memo.end()) {
            return memo[i];
        }

        int maxJump=nums[i];
        for(int jump=1;jump<=maxJump;jump++) {
            if(i+jump<nums.size() && dfs(nums,i+jump)) {
                return memo[i]=true;
            }
        }

        return memo[i]=false;
    }
    bool canJump(vector<int>& nums) {
        return dfs(nums,0);
    }
};