// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<bool>> vis(image.size(),vector<bool> (image[0].size(),false));
        
        int color=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        vis[sr][sc]=true;
        image[sr][sc]=newColor;
        
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                
                for(int j=0;j<4;j++) {
                    int nx=a+dx[j];
                    int ny=b+dy[j];
                    
                    if(nx>=0 && ny>=0 && nx<image.size() && ny<image[0].size()) {
                        if(!vis[nx][ny] && image[nx][ny]==color) {
                            q.push({nx,ny});
                            image[nx][ny]=newColor;
                            vis[nx][ny]=true;
                        }
                    }
                }
            }
        }
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends