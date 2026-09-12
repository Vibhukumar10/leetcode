class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;

        vector<int> indegree(numCourses,0);
        for(vector<int> pre:prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int u=q.front();
                q.pop();

                res.push_back(u);

                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v]==0) {
                        q.push(v);
                    }
                }
            }
        }
        if(res.size()!=numCourses) {
            return {};
        }
        return res;
    }
};