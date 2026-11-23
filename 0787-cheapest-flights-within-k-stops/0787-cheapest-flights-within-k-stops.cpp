class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        distance[src]=0;

        unordered_map<int, vector<pair<int,int>>> adj;

        for(vector<int> &vec:flights) {
            int u=vec[0];
            int v=vec[1];
            int cost=vec[2];

            adj[u].push_back({v,cost});
        }

        
        queue<pair<int,int>> q;
        q.push({src,0});

        int stops=0;

        while(!q.empty() && stops<=k) {
            int sz=q.size();
            while(sz--) {
                auto [u,c]=q.front();
                q.pop();
                
                for(auto &V:adj[u]) {
                    int v=V.first;
                    int cost=V.second;

                    if(distance[v]>cost+c) {
                        distance[v]=cost+c;
                        q.push({v,cost+c});
                    }
                }

            }
            stops++;
        }

        return distance[dst]==INT_MAX?-1:distance[dst];
    }
};