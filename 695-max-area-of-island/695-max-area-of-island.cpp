class Solution {
public:
    int bfs(vector<vector<int>> &vis,vector<vector<int>> &grid,int x,int y) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        int res=0;
        
        q.push({x,y});
        vis[x][y]=1;
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int qx=q.front().first;
                int qy=q.front().second;
                q.pop();
                
                res++;
                
                if(qx+1<n && grid[qx+1][qy]==1 && !vis[qx+1][qy]) {
                    q.push({qx+1,qy});
                    vis[qx+1][qy]=1;
                }
                if(qx-1>=0 && grid[qx-1][qy]==1 && !vis[qx-1][qy]) {
                    q.push({qx-1,qy});
                    vis[qx-1][qy]=1;
                }
                if(qy+1<m && grid[qx][qy+1]==1 && !vis[qx][qy+1]) {
                    q.push({qx,qy+1});
                    vis[qx][qy+1]=1;
                }
                if(qy-1>=0 && grid[qx][qy-1]==1 && !vis[qx][qy-1]) {
                    q.push({qx,qy-1});
                    vis[qx][qy-1]=1;
                }
            }
        }
        return res;        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        int res=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]==0 && grid[i][j]==1) {
                    res=max(res,bfs(vis,grid,i,j));
                }
            }
        }
        return res;
    }
};