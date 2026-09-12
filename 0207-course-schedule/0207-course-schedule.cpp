class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int cur=0;
        while(!q.empty()) {
            int course=q.front();
            q.pop();

            cur++;

            for(int v:adj[course]) {
                indegree[v]--;
                if(indegree[v]==0) {
                    q.push(v);
                }
            }
        }
        
        return cur==numCourses;
    }
};

// 0 -> 1