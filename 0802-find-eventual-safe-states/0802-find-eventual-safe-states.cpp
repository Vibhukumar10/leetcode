class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,vector<int>> adj;

        vector<int> indegree(n,0);

        for(int i=0;i<n;i++) {
            for(int node:graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        
        for(int i=0;i<n;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        vector<bool> isSafe(n,false);
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int node=q.front();
                q.pop();

                isSafe[node]=true;

                for(int nei:adj[node]) {
                    indegree[nei]--;
                    if(indegree[nei]==0) {
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++) {
            if(isSafe[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};