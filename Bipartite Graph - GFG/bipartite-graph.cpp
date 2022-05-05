// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(int V,int s,vector<int> adj[],vector<bool> &vis,unordered_map<int,int> &mp) {
	    queue<int> q;
	    
	    q.push(s);
	    mp[s]=1;
	    vis[s]=true;
	    
	    while(!q.empty()) {
	        int sz=q.size();
	        for(int i=0;i<sz;i++) {
	            int u=q.front();
	            q.pop();
	            
	            for(int v:adj[u]) {
    	            if(!vis[v]) {
    	                if(mp[u]==1) {
    	                    mp[v]=2;
    	                } else if(mp[u]==2) {
    	                    mp[v]=1;
    	                }
    	                q.push(v);
    	                vis[v]=true;
    	            } else {
    	                if(mp[u]==mp[v]) {
    	                    return false;
    	                }
    	            }
	            }
	        }
	    }
	    
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool> vis(V,false);
	    
	    unordered_map<int,int> mp;
	    for(int i=0;i<V;i++) {
	        mp[i]=0;
	    }
	    
	    for(int i=0;i<V;i++) {
	        if(!vis[i]) {
	            if(!helper(V,i,adj,vis,mp)) {
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends