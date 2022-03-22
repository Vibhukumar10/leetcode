class Solution {
public:
    int helper(string text1,int n,string text2,int m) {
//         if(n==0 || m==0) return 0;
        
//         if(text1[n-1]==text2[m-1]) return 1+helper(text1,n-1,text2,m-1);
        
//         return max(helper(text1,n-1,text2,m),helper(text1,n,text2,m-1));
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0) 
                {
                    dp[i][j]=0;
                    continue;
                }
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1,text1.length(),text2,text2.length());
    }
};