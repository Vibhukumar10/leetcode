class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int currNode, vector<int> &color, int currColor) {
        color[currNode]=currColor;

        for(int &v:graph[currNode]) {
            if(color[v]==-1) {
                if(!dfs(graph,v,color,(currColor+1)%2)) {
                    return false;
                }
            } else if(color[v]==currColor) {
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<int> color(V,-1);

        for(int i=0;i<V;i++) {
            if(color[i]==-1) {
                if(!dfs(graph,i,color,0)) {
                    return false;
                }
            }
        }

        return true;
    }
};