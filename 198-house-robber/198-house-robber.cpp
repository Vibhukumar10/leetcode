class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) {
            return nums[0];
        }
        
        vector<int> dp(3,0);
        
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        
        for(int i=3;i<=nums.size();i++) {
            int pick = nums[i-1] + dp[(i-2)%3];
            int np = dp[(i-1)%3];
            dp[i%3] = max(pick,np);
        }
        return max(dp[n%3],dp[(n-1)%3]);
    }
};