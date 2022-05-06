// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(int s,int V,vector<int> adj[],vector<bool> &vis) {
        queue<pair<int,int>> q;
        q.push({s,-1});
        vis[s]=true;
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int u=q.front().first;
                int p=q.front().second;
                q.pop();
                
                for(int v:adj[u]) {
                    if(!vis[v]) {
                        q.push({v,u});
                        vis[v]=true;
                    } else {
                        if(v!=p) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(cycle(i,V,adj,vis)) {
                    return true;
                }
            }
        }
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends