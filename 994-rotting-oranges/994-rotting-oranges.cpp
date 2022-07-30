class Solution {
public:
    void bfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &m) {
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        
        int tim=0;
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                m[x][y] = min(m[x][y],tim);
                
                if(x-1>=0 && !vis[x-1][y]) {
                    vis[x-1][y]=1;
                    q.push({x-1,y});                    
                }
                if(y-1>=0 && !vis[x][y-1]) {
                    vis[x][y-1]=1;
                    q.push({x,y-1});                    
                }
                if(x+1<grid.size() && !vis[x+1][y]) {
                    vis[x+1][y]=1;
                    q.push({x+1,y});                    
                }if(y+1<grid[0].size() && !vis[x][y+1]) {
                    vis[x][y+1]=1;
                    q.push({x,y+1});                    
                }
            }
            tim++;
        }
        
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        //if disconnected -> not possible
//         int tim=INT_MIN;
//         vector<vector<int>> m(grid.size(),vector<int> (grid[0].size(),INT_MAX));
        
//         int count=0;
        
//         for(int i=0;i<grid.size();i++) {
//             for(int j=0;j<grid[0].size();j++) {
//                 if(grid[i][j] == 2) {
//                     count++;
//                     bfs(i,j,grid,m);
//                 }
//             }
//         }
        
//         if(count==0) {
//             return -1;
//         }
        
//         for(int i=0;i<grid.size();i++) {
//             for(int j=0;j<grid[0].size();j++) {
//                 if(grid[i][j] && m[i][j]==INT_MAX) {
//                     return -1;
//                 }
//                 if(grid[i][j] != INT_MAX) tim = max(tim,m[i][j]);
//             }
//         }
        
//         return tim;
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
    }
};