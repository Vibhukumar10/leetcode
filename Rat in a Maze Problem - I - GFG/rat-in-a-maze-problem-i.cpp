// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(vector<string> &res,vector<vector<int>> &m,int n,int x,int y,string curr,vector<vector<bool>> vis) {
        if(x<0 || y<0 || x>=n || y>=n || m[x][y]==0 || vis[x][y]) {
            return;
        } else if(x==n-1 && y==n-1) {
            res.push_back(curr);
        } else {
            vis[x][y]=true;
            dfs(res,m,n,x,y+1,curr+"R",vis);
            dfs(res,m,n,x-1,y,curr+"U",vis);
            dfs(res,m,n,x+1,y,curr+"D",vis);
            dfs(res,m,n,x,y-1,curr+"L",vis);
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<bool>> vis(n,vector<bool> (n,false));
        dfs(res,m,n,0,0,"",vis);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends