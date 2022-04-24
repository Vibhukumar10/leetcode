// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfsRec(int s,vector<int> adj[],bool visited[],int parent) {
        visited[s]=true;
        
        for(int v:adj[s]) {
            if(!visited[v]) {
                if(dfsRec(v,adj,visited,s)) {
                    return true;
                }
            } else if(v!=parent) {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V];
        for(int i=0;i<V;i++) {
            visited[i]=false;
        }
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(dfsRec(i,adj,visited,-1)) {
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