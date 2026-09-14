class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& flight:flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to,price});
        }

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        queue<pair<int,int>> pq;
        pq.push({0,src});

        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        int stops=0;

        while(!pq.empty() && stops<=k) {
            stops++;
            int sz=pq.size();
            while(sz--) {
                auto [dis,u]=pq.front();
                pq.pop();

                for(auto it:adj[u]) {
                    auto [v,weight]=it;

                    if(dis+weight<dist[v]) {
                        dist[v]=dis+weight;
                        pq.push({dist[v],v});
                    }
                }
            }
        }
        

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};