class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j) {
        int n=grid.size(),m=grid[0].size();

        grid[i][j]='0';

        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};

        for(int d=0;d<4;d++) {
            int nx=i+dx[d];
            int ny=j+dy[d];

            if(nx>=n || nx<0 || ny>=m || ny<0) {
                continue;
            }

            if(grid[nx][ny]=='1') {
                dfs(grid,nx,ny);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();

        int count=0;
        // vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]=='1') {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }

        return count;
    }
};