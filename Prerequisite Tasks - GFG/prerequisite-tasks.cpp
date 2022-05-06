// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++) {
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    } 
	    
	    vector<int> in(N,0);
	    for(int u=0;u<N;u++) {
	        for(int v:adj[u]) {
	            in[v]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++) {
	        if(in[i]==0) {
	            q.push(i);
	        }
	    }
	    
	    if(q.empty()) {
	        return false;
	    }
	    
	    vector<int> topo;
	    while(!q.empty()) {
	        int sz=q.size();
	        for(int i=0;i<sz;i++) {
	            int u=q.front();
	            q.pop();
	            
	            topo.push_back(u);
	            
	            for(int v:adj[u]) {
	                in[v]--;
	                if(in[v]==0) {
	                    q.push(v);
	                }
	            }
	        }
	    }
	    return topo.size()==N;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends