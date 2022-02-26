// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs(int i,int j,vector<vector<bool>> &visited,vector<vector<char>> &grid,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j]=='0') return;
        
        if(!visited[i][j])
        {
            visited[i][j]=true;
            dfs(i+1,j,visited,grid,n,m);
           dfs(i-1,j,visited,grid,n,m);
           dfs(i,j+1,visited,grid,n,m);
           dfs(i,j-1,visited,grid,n,m);
           dfs(i+1,j+1,visited,grid,n,m);
           dfs(i-1,j-1,visited,grid,n,m);
           dfs(i+1,j-1,visited,grid,n,m);
           dfs(i-1,j+1,visited,grid,n,m);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
       
       int count=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(!visited[i][j] and grid[i][j]=='1')
               {
                   dfs(i,j,visited,grid,n,m);
                   count++;
               }
           }
       }
       return count;
        
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