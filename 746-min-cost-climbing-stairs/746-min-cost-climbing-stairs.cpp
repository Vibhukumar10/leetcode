class Solution {
public:
//     int helper(vector<int> &cost,int n) {
//         if(n<=0) {
//             return 0;
//         }
        
//         int pick = cost[n-1] + helper(cost,n-1);
//         int np = helper(cost,n-2);
//         // int np = 1e9;
        
//         return min(pick,np);
//     }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        // int res=INT_MAX;
        // dp=vector<int> (1001,-1);
        // helper(res,0,cost,0);
        // helper(res,0,cost,1);
        // return res;
        
        // return min(helper(cost,cost.size()-1),helper(cost,cost.size()-2));
        
        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=cost[0];
        // dp[2]=min(cost[0],cost[1]);
        dp[2]=cost[1];
        for(int i=3;i<=n;i++) {
            dp[i]=cost[i-1]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n],dp[n-1]);
        // return dp[n];
    }
};