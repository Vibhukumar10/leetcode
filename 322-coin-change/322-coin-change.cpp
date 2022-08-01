class Solution {
public:
    int helper(int n,vector<int> &coins,int amount,vector<vector<int>> &dp) {
        //base
        if(n==0) {
            return 1e9;
        } else if(amount==0) {
            return 0;
        }
        
        if(dp[n][amount]!=-1) return dp[n][amount];
        
        int np = helper(n-1,coins,amount,dp);
        int pick=INT_MAX;
        
        if(amount-coins[n-1]>=0) {
            pick = 1 + helper(n,coins,amount-coins[n-1],dp);
        }
        
        return dp[n][amount] = min(pick,np);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1,-1));
        int res = helper(coins.size(),coins,amount,dp);
        
        
        return res >= 1e9 ? -1:res;
    }
};