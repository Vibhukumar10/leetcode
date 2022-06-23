class Solution {
public:
    void helper(int &res,int curr,vector<int> &cost,int ind) {
        if(ind>=cost.size()) {
            res=min(res,curr);
            return;
        }
        
        curr+=cost[ind];
        helper(res,curr,cost,ind+1);        
        helper(res,curr,cost,ind+2);        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // int res=INT_MAX;
        // dp=vector<int> (1001,-1);
        // helper(res,0,cost,0);
        // helper(res,0,cost,1);
        // return res;
        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++) {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};