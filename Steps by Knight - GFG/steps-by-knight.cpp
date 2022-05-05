// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
	    // Code here
	    vector<int> dirx={1,1,-1,-1,2,2,-2,-2};
	    vector<int> diry={2,-2,2,-2,1,-1,1,-1};
	    
	    vector<vector<bool>> vis(N+1,vector<bool> (N+1,false));
	    
	    queue<pair<int,pair<int,int>>> q;
	    q.push({KnightPos[0],{KnightPos[1],0}});
	    vis[KnightPos[0]][KnightPos[1]]=true;
	    
	    while(!q.empty()) {
	        int sz=q.size();
	        for(int i=0;i<sz;i++) {
	            pair<int,pair<int,int>> p=q.front();
	            q.pop();
	            
	            if(p.first==TargetPos[0] && p.second.first==TargetPos[1]) {
	                return p.second.second;
	            }
	            
	            for(int j=0;j<8;j++) {
	                int x=p.first+dirx[j];
	                int y=p.second.first+diry[j];
	                
	                if(x>=1 && x<=N && y>=1 && y<=N && !vis[x][y]) {
	                    vis[x][y]=true;
	                    q.push({x,{y,p.second.second+1}});
	                }
	            }
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends