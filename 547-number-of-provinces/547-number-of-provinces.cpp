class Solution {
public:
    void dfsRec(int s,vector<vector<int>> &adj,bool visited[])
    {
        visited[s]=true;
        
        for(int i=0;i<adj[s].size();i++)
        {
            if(adj[s][i]!=0 && !visited[i])
                dfsRec(i,adj,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=false;
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfsRec(i,isConnected,visited);
            }
        }
        return count;
    }
};