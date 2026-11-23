class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=true;

        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto [x,y]=q.front();
                q.pop();

                if(x-1>=0 && image[x-1][y]==image[x][y] && !vis[x-1][y]) {
                    vis[x-1][y]=true;
                    q.push({x-1,y});
                }
                if(y-1>=0 && image[x][y-1]==image[x][y] && !vis[x][y-1]) {
                    vis[x][y-1]=true;
                    q.push({x,y-1});
                }
                if(x+1<n && image[x+1][y]==image[x][y] && !vis[x+1][y]) {
                    vis[x+1][y]=true;
                    q.push({x+1,y});
                }
                if(y+1<m && image[x][y+1]==image[x][y] && !vis[x][y+1]) {
                    vis[x][y+1]=true;
                    q.push({x,y+1});
                }

                image[x][y]=color;
            }
        }

        return image;
    }
};