class Solution {
public:
    
//     int fun(string s1,string s2,int m,int n)
//     {
//         if(n==0||m==0)
//             return 0;
        
//         if(s1[m-1]==s2[n-2])
//             return 1+fun(s1,s2,m-1,n-1);
//         else
//             return max(fun(s1,s2,m-1,n),fun(s1,s2,m,n-1));
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                
                else
                {
                    if(text1[i-1]==text2[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};