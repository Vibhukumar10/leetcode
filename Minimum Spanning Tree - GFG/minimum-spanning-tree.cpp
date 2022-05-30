// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<bool> mset(V,false);
        vector<int> key(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        mset[0]=true;
        key[0]=0;
        pq.push({0,0});
        
        while(!pq.empty()) {
            int u=pq.top().second;
            pq.pop();
            
            mset[u]=true;
            
            for(auto it:adj[u]) {
                int v=it[0];
                int w=it[1];
                
                if(!mset[v] && w<key[v]) {
                    key[v]=w;
                    pq.push({w,v});
                }
            }
        }
        
        int res=0;
        for(int x:key) {
            res+=x;
        }
        return res;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends