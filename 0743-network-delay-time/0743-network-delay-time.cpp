class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto it:times) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()) {
            auto [dis,node]=pq.top();
            pq.pop();

            for(auto it:adj[node]) {
                auto [adjNode,weight]=it;
                if(dis+weight<dist[adjNode]) {
                    dist[adjNode]=dis+weight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int res=0;
        for(int i=1;i<=n;i++) {
            res=max(res,dist[i]);
        }

        return res==INT_MAX?-1:res;
    }
};