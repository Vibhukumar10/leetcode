// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> grid,int n,int m,int i,int j,vector<vector<bool>> &vis) {
        vis[i][j]=true;
        
        int dirx[]={0,0,1,1,1,-1,-1,-1};
        int diry[]={1,-1,-1,0,1,-1,0,1};
        
        for(int k=0;k<8;k++) {
            int x=i+dirx[k];
            int y=j+diry[k];
            
            if(x<n && x>=0 && y<m && y>=0) {
                if(grid[x][y]=='1' && !vis[x][y]) {
                    dfs(grid,n,m,x,y,vis);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(grid.size(),vector<bool> (grid[0].size(),false));
        
        int res=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    dfs(grid,n,m,i,j,vis);
                    res++;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends