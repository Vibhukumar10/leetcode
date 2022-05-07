// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    bool isValid(int x,int y,int n) {
        return (x>=0 && x<n && y>=0 && y<n);
    }
    
    //Function to find whether a path exists from the source to destination.
    bool dfs(vector<vector<int>>& grid,int sx,int sy,int dx,int dy,vector<vector<bool>> &vis) {
        vis[sx][sy]=true;
        
        if(grid[sx][sy]==0) {
            return false;
        } else if(sx==dx && sy==dy) {
            return true;
        }
        
        
        int dirx[]={0,1,0,-1};
        int diry[]={1,0,-1,0};
        
        bool is=false;
        for(int i=0;i<4;i++) {
            int nSx=sx+dirx[i];
            int nSy=sy+diry[i];
            
            if(isValid(nSx,nSy,grid.size())) {
                if(!vis[nSx][nSy]) {
                    if(dfs(grid,nSx,nSy,dx,dy,vis)) {
                        is=true;
                    }
                }
            }
        }
        
        return is;
    }
    
    bool is_Possible(vector<vector<int>>& grid) {
        //code here
        int srcx,srcy,desx,desy;
        bool c1=false,c2=false;
        for(int i=0;i<grid.size();i++) {
            if(c1 && c2) {
                break;
            }
            for(int j=0;j<grid.size();j++) {
                if(grid[i][j]==1) {
                    c1=true;
                    srcx=i;
                    srcy=j;
                } else if(grid[i][j]==2) {
                    c2=true;
                    desx=i;
                    desy=j;
                }
            }
        }
        // cout<<srcx<<" "<<srcy<<" "<<desx<<" "<<desy<<" ";
        vector<vector<bool>> vis(grid.size(),vector<bool> (grid[0].size(),false));
        
        return dfs(grid,srcx,srcy,desx,desy,vis);
        // return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends