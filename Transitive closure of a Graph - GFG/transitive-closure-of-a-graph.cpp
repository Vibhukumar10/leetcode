// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
        vector<vector<int>> path;
        
        for(int s=0;s<N;s++) {
            queue<int> q;
            q.push(s);
            vector<bool> vis(N,false);
            vector<int> bfs(N,0);
            
            while(!q.empty()) {
                int sz=q.size();
                for(int i=0;i<sz;i++) {
                    int u=q.front();
                    q.pop();
                    
                    for(int k=0;k<N;k++) {
                        if((graph[u][k]==1 || k==u) && !vis[k]) {
                            vis[k]=true;
                            bfs[k]=1;
                            q.push(k);
                        }
                    }
                }
            }
            path.push_back(bfs);
        }
        return path;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}  // } Driver Code Ends