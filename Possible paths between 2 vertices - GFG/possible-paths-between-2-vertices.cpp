// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void dfs(int &res,vector<int> adj[],int src,int des,vector<bool> &vis) {
        vis[src]=true;
        
        if(src==des) {
            res++;
            vis[src]=false;
            return;
        }
        
        for(int v:adj[src]) {
            if(!vis[v]) {
                dfs(res,adj,v,des,vis);
            }
        }
        vis[src]=false;
    }
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<bool> vis(V,false);
        int res=0;
        dfs(res,adj,source,destination,vis);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends