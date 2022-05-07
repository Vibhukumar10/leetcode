// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> in(V,0);
        
        for(int i=0;i<V;i++) {
            for(int v:adj[i]) {
                if(v==i) {
                    return true;
                }
            }
        }
        
        for(int i=0;i<V;i++) {
            for(int v:adj[i]) {
                in[v]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(in[i]==0) {
                q.push(i);
            }
        }
        
        int count=0;
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int u=q.front();
                q.pop();
                
                count++;
                // cout<<u<<" ";
                
                for(int v:adj[u]) {
                    in[v]--;
                    if(in[v]==0) {
                        q.push(v);
                    }
                }
            }
        }
        
        return !(count==V);
        
        // vector<bool> vis(V,false);
        // for(int i=0;i<V;i++) {
        //     if(!vis[i]) {
        //         if(cycle(i,adj,vis)) {
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends