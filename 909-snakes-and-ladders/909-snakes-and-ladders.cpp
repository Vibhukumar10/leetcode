class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int,int>> q;
        q.push({1,0});
        int n=board.size();
        
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        unordered_map<int,pair<int,int>> mp;
        
        bool Odd = (n)%2;
        
        int curr=n*n;
        for(int i=0;i<n;i++) {
            if((i+n)%2==0) {
                for(int j=0;j<n;j++) {
                    mp[curr--] = {i,j};
                }
            } else {
                for(int j=n-1;j>=0;j--) {
                    mp[curr--] = {i,j};
                }
            }
        }
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int curr=q.front().first;
                int step=q.front().second;
                q.pop();
                
                if(curr==n*n) {
                    return step;
                }
                
                
                for(int i=1;i<=6;i++) {
                    int ncur=curr+i;
                    
                    if(ncur<=n*n) {
                        int x=mp[ncur].first;
                        int y=mp[ncur].second;
                        
                        // cout<<x<<" "<<y<<"\n";
                        

                        if(!vis[x][y]) {
                            if(board[x][y]!=-1) {
                                q.push({board[x][y],step+1});
                            } else {
                                q.push({ncur,step+1});
                            }
                            vis[x][y]=true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};