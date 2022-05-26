// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isValid(int rx,int ry,int n,int m) {
        return (rx<n && ry<m && rx>=0 && ry>=0);
    }
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    bool dfs(vector<vector<char>> board,vector<vector<bool>> &vis,string word,int index,int x, int y) {
        if(index >= word.length() || board[x][y]!=word[index] || vis[x][y]) {
            return false;
        }
        
        if(index==word.length()-1 && board[x][y]==word[index]) {
            return true;
        }
        
        vis[x][y]=true;
        
        bool check=false;
        for(int i=0;i<4;i++) {
            int rx=x+dx[i];
            int ry=y+dy[i];
            
            if(isValid(rx,ry,board.size(),board[0].size()) && !vis[rx][ry] && index<word.length()-1 && board[rx][ry]==word[index+1]) {
                if(dfs(board,vis,word,index+1,rx,ry)) {
                    check=true;
                }
            }
        }
        
        vis[x][y]=false;
        
        return check;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        vector<vector<bool>> vis(board.size(),vector<bool> (board[0].size(),false));
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j]==word[0]) {
                    if(dfs(board,vis,word,0,i,j)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends