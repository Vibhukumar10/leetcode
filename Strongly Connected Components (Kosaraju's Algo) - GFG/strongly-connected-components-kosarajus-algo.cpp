// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs(int V,int s,vector<int> adj[],vector<bool> &vis) {
	    vis[s]=true;
	    
	    for(int v:adj[s]) {
	        if(!vis[v]) {
	            dfs(V,v,adj,vis);
	        }
	    }
	}
	
	void fillorder(int s,vector<int> adj[],vector<bool> &vis,stack<int> &st) {
	    vis[s]=true;
	    
	    for(int v:adj[s]) {
	        if(!vis[v]) {
	            fillorder(v,adj,vis,st);
	        }
	    }
	    
	    st.push(s);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]) {
        
        stack<int> st;
        vector<bool> vis(V,false);
        
        for(int u=0;u<V;u++) {
            if(!vis[u]) {
                fillorder(u,adj,vis,st);
            }
        }
        
        
        for(int i=0;i<V;i++) vis[i]=false;
        
        vector<int> revAdj[V];
        for(int i=0;i<V;i++) {
            for(int v:adj[i]) {
                revAdj[v].push_back(i);
            }
        }
        
        int res=0;
        while(!st.empty()) {
            int i=st.top();
            st.pop();
            
            if(!vis[i]) {
                res++;
                dfs(V,i,revAdj,vis);
            }
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends