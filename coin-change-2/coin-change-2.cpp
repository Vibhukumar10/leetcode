class Solution {
public:
//     int memo[5001][301];
//     int helper(vector<int> coins,int n,int sum)
//     {
//         if(memo[sum][n]==-1)
//         {   
//             if(sum==0)
//                 memo[sum][n] = 1;

//             else if(n==0)
//                 memo[sum][n] = 0; 
            
//             else
//             {
//                 int res=helper(coins,n-1,sum);
//                 if(sum>=coins[n-1])
//                     res+=helper(coins,n,sum-coins[n-1]);
//                 memo[sum][n] = res;
//             }
//         }
//         return memo[sum][n];
//     }
    
    int change(int amount, vector<int>& coins) {
        // memset(memo,-1,sizeof(memo));
        int n=coins.size();
        
        int dp[amount+1][n+1];
        for(int i=0;i<=amount;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=1;
                else
                {
                    dp[i][j]=dp[i][j-1];
                    if(i>=coins[j-1])
                        dp[i][j]+=dp[i-coins[j-1]][j];
                }
            }
        }
        return dp[amount][n];
    }
};