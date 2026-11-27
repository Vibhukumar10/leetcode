class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int u, vector<bool> &vis) {
        vis[u]=true;

        for(int i=0;i<isConnected.size();i++) {
            if(isConnected[u][i] && !vis[i]) {
                dfs(isConnected,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();

        vector<bool> vis(V,false);

        int count=0;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                count++;
                dfs(isConnected,i,vis);
            }
        }

        return count;
    }
};