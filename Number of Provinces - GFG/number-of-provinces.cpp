// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfsRec(int s,vector<vector<int>> adj,vector<bool> &vis) {
      vis[s]=true;
      
      for(int i=0;i<adj[s].size();i++) {
          if(adj[s][i]==1 && !vis[i]) {
              dfsRec(i,adj,vis);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> vis(V,false);
        
        int res=0;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                res++;
                dfsRec(i,adj,vis);
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends