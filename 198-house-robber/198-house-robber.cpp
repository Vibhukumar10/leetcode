class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) {
            return nums[0];
        }
        
        vector<int> dp(nums.size()+1,0);
        
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        
        for(int i=3;i<=nums.size();i++) {
            int pick = nums[i-1] + dp[i-2];
            int np = dp[i-1];
            dp[i] = max(pick,np);
        }
        return max(dp[n],dp[n-1]);
    }
};