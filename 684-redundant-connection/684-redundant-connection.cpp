class Solution {
public:
    bool dfs(int s,int fs,int d,vector<int> adj[],vector<bool> vis) {
        vis[s]=true;
        
        if(s==d) return true;
        
        for(int v:adj[s]) {
            if((s==fs && v==d) || (s==d && v==fs)) continue;
            if(!vis[v]) {
                if(dfs(v,fs,d,adj,vis)) return true;
            }
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> adj[edges.size()+1];
        
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(edges.size()+1,false);
        
        for(int i=edges.size()-1;i>=0;i--) {
            if(dfs(edges[i][0],edges[i][0],edges[i][1],adj,vis)) {
                return {edges[i][0],edges[i][1]};
            }
        }
        return {};
    }
};