class Solution {
public:
    int memo[5001][301];
    int helper(vector<int> coins,int n,int sum)
    {
        if(memo[sum][n]==-1)
        {   
            if(sum==0)
                memo[sum][n] = 1;

            else if(n==0)
                memo[sum][n] = 0; 
            
            else
            {
                int res=helper(coins,n-1,sum);
                if(sum>=coins[n-1])
                    res+=helper(coins,n,sum-coins[n-1]);
                memo[sum][n] = res;
            }
        }
        return memo[sum][n];
    }
    
    int change(int amount, vector<int>& coins) {
        memset(memo,-1,sizeof(memo));
        return helper(coins,coins.size(),amount);
    }
};