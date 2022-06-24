class Solution {
public:
    // vector<int> dp;
    // int helper(int &res,int curr,vector<int> &nums,int n) {
    //     if(dp[n]!=-1) {
    //         if(n<0) {
    //             res=max(curr,res);
    //             dp[n]=res;
    //         } else {
    //             helper(res,curr+nums[n],nums,n-2);
    //             helper(res,curr,nums,n-1);
    //         }
    //     } 
    //     return dp[n];
    // }
    
    int rob(vector<int>& nums) {
        int res=0,n=nums.size();
        // dp=vector<int> (n+1,-1);
        // helper(res,0,nums,n-1);
        // return res;
        if(n==1) {
            return nums[0];
        }
        
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++) {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};