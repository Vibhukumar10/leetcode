// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<int> adj[n];
	    for(int i=0;i<pre.size();i++) {
	        adj[pre[i][1]].push_back(pre[i][0]);
	    } 
	    
	    vector<int> in(n,0);
	    for(int u=0;u<n;u++) {
	        for(int v:adj[u]) {
	            in[v]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<n;i++) {
	        if(in[i]==0) {
	            q.push(i);
	        }
	    }
	    
	    if(q.empty()) {
	        return {};
	    }
	    
	    vector<int> topo;
	    while(!q.empty()) {
	        int sz=q.size();
	        for(int i=0;i<sz;i++) {
	            int u=q.front();
	            q.pop();
	            
	            topo.push_back(u);
	            
	            for(int v:adj[u]) {
	                in[v]--;
	                if(in[v]==0) {
	                    q.push(v);
	                }
	            }
	        }
	    }
	    if(topo.size()==n) {
	        return topo;
	    }
	    return {};
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends