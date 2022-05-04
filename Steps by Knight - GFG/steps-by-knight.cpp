// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    struct cell {
        int x,y,dis;
        cell (int xx,int yy,int diss) {
            x=xx;
            y=yy;
            dis=diss;
        }
    };
    
    bool isValid(int x,int y,int N) {
        if(x < 1 || x > N || y < 1 || y > N) {
            return false;
        } return true;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
	    // Code here
	    cell t(TargetPos[0],TargetPos[1],0);
	    
	    int dirx[8]={2,2,1,1,-2,-2,-1,-1};
	    int diry[8]={1,-1,2,-2,1,-1,2,-2};
	    
	    int x,y;
	    
	    vector<vector<bool>> vis(N+1,vector<bool> (N+1,false));
	    queue<cell> q;
	    q.push(cell(KnightPos[0],KnightPos[1],0));
	    vis[KnightPos[0]][KnightPos[1]]=true;
	    
	    while(!q.empty()) {
	        cell k=q.front();
	        q.pop();
	        
	        if(k.x==t.x && k.y==t.y) {
	            return k.dis;
	        }
	        
	        for(int i=0;i<8;i++) {
	            x=k.x+dirx[i];
	            y=k.y+diry[i];
	            
	            if(isValid(x,y,N) && !vis[x][y]) {
	                vis[x][y]=true;
	                q.push(cell(x,y,k.dis+1));
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