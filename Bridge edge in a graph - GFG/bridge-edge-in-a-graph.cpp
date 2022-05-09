// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void bfs(int s,vector<bool> &vis,int c,int d,vector<int> adj[]) {
        queue<int> q;
        q.push(s);
        vis[s]=true;
        // int res=0;
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int u=q.front();
                q.pop();
                
                // res++;
                
                for(int v:adj[u]) {
                    if((u==d && v==c) || (u==c && v==d)) {
                        continue;
                    } else {
                        if(!vis[v]) {
                            q.push(v);
                            vis[v]=true;
                        }
                    }
                }
            }
        }
        // return res;
    }
    
    void dfs(int s,vector<bool> &vis,int c,int d,vector<int> adj[]) {
        vis[s]=true;
        
        for(int v:adj[s]) {
            if(!vis[v]) {
                dfs(v,vis,c,d,adj);
            }
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> vis(V,false);
        // bfs(0,vis,c,d,adj);
        int init=0,res=0;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i,vis,c,d,adj);
                init++;
            }
        }
        
        for(int i=0;i<V;i++) {
            vis[i]=false;
        }
        
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                bfs(i,vis,c,d,adj);
                res++;
            }
        }
        return !(res==init);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends