class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();

        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++) {
            for(int node:rooms[i]) {
                adj[i].push_back(node);
            }
        }

        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);
        vis[0]=true;

        int res=0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int node=q.front(); q.pop();
                
                res++;

                for(int nei:adj[node]) {
                    if(!vis[nei]) {
                        vis[nei]=true;
                        q.push(nei);
                    }
                }
            }
        }

        return res==n;
    }
};