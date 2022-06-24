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
    
    int f(int ind,vector<int> &nums,vector<int> &dp) {
        if(ind<0) {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        
        return dp[ind]=max(f(ind-1,nums,dp),nums[ind]+f(ind-2,nums,dp));
    }
    
    int rob(vector<int>& nums) {
        int res=0,n=nums.size();
        
        if(n==1) {
            return nums[0];
        }
        
        vector<int> dp(n,0);
        
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++) {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
        
        // // dp=vector<int> (n+1,-1);
        // // helper(res,0,nums,n-1);
        // // return res;
        // vector<int> dp(n,-1);
        // return f(n-1,nums,dp);
    }
};