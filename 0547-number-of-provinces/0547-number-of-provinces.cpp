class Solution {
public:
    void dfs(vector<bool> &vis,vector<vector<int>> &isConnected, int i) {
        int n=isConnected.size();
        
        for(int j=0;j<n;j++) {
            if(isConnected[i][j]==1 && !vis[j]) {
                vis[j]=true;
                dfs(vis,isConnected,j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);

        int count=0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                count++;
                vis[i]=true;
                dfs(vis,isConnected,i);
            }
        }

        return count;
    }
};