// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    bool bfs(int s,int V,vector<int> adj[]) {
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(s);
        vis[s]=true;
        
        int count=0;
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int u=q.front();
                q.pop();
                
                count++;
                
                for(int v:adj[u]) {
                    if(!vis[v]) {
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
        
        return count==V;
    }
    
	int findMotherVertex(int V, vector<int>adj[]) {
	    // Code here
	    for(int i=0;i<V;i++) {
	        if(bfs(i,V,adj)) {
	            return i;
	        }
	    }
	    return -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends