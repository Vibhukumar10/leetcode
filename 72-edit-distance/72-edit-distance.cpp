class Solution {
public:
    int edit(string a,int n,string b,int m) {
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0 && j==0) dp[i][j]=0;
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else {
                    if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                    else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        return edit(word1,word1.size(),word2,word2.size());
    }
};