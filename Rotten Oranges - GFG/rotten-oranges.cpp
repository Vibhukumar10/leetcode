// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                    grid[i][j]=0;
                }
            }
        }
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        int res=-1;
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int a=q.front().first.first;
                int b=q.front().first.second;
                int timee=q.front().second;
                q.pop();
                
                res=timee;
                
                for(int j=0;j<4;j++) {
                    int nx=a+dx[j];
                    int ny=b+dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size()) {
                        if(grid[nx][ny]==1) {
                            q.push({{nx,ny},timee+1});
                            grid[nx][ny]=0;
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]!=0) {
                    return -1;
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends