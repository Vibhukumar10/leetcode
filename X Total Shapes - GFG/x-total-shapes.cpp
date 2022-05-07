// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    bool isValid(int x,int y,int n,int m) {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    void bfs(vector<vector<char>> grid,int x,int y,vector<vector<bool>> &vis) {
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=true;
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++) {
                    int nx=a+dx[i];
                    int ny=b+dy[i];
                    if(isValid(nx,ny,grid.size(),grid[0].size())) {
                        if(!vis[nx][ny] && grid[nx][ny]=='X') {
                            vis[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
                
            }
        }
    }
    
    int xShape(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]=='X') {
                    res++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends