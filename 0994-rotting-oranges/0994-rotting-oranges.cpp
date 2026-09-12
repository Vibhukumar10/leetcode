class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int fresh=0;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }

                if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }

        if(q.empty() && fresh==0) {
            return 0;
        }

        int minutes=-1;
        vector<int> dr={0,0,1,-1};
        vector<int> dc={1,-1,0,0};

        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto [r,c]=q.front();
                q.pop();

                for(int d=0;d<4;d++) {
                    int nr=r+dr[d];
                    int nc=c+dc[d];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1) {
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                    }

                }

            }
            minutes++;
        }

        if(fresh>0) {
            return -1;
        }

        return minutes;
    }
};