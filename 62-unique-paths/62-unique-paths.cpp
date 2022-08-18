class Solution {
public:
    int dfs(int x,int y,int m,int n,vector<vector<int>> vis,vector<vector<int>> &dp) {
        if(x==m-1 && y==n-1) {
            return 1;
        } else if(x<0 || y<0 || x>=m || y>=n) {
            return 0;
        }
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        vis[x][y]=1;
        int down = dfs(x+1,y,m,n,vis,dp);
        int right = dfs(x,y+1,m,n,vis,dp);
        
        return dp[x][y] = down+right;
    }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>> vis(m,vector<int> (n,0));
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        vector<vector<int>> dp (m, vector<int> (n,1));
        
        for(int j=1;j<n;j++) {
            for (int i=1;i<m;i++) {
                dp[i][j] = dp[i][(j-1)] + dp[(i-1)][j];
            }
            
        }
        
        return dp[(m-1)][n-1];
        
        // return dfs(0,0,m,n,vis,dp);
    }
};