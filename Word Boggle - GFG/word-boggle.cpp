// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>> &board,string word,int i,int j,int len) {
        if(len == word.size())
            return true;
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size())
            return false;
        if(board[i][j] != word[len])
            return false;
        board[i][j] = '*';
        bool ans = 
        dfs(board, word, i-1, j, len+1) || //up
        dfs(board, word, i+1, j, len+1) || //down
        dfs(board, word, i, j-1, len+1) || //left
        dfs(board, word, i, j+1, len+1) || //right
        dfs(board, word, i-1, j+1, len+1) || //top-right
        dfs(board, word, i-1, j-1, len+1) || //top-left
        dfs(board, word, i+1, j+1, len+1) || //br
        dfs(board, word, i+1, j-1, len+1); // bl
        board[i][j] = word[len];
        return ans;
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<bool> isFound(dictionary.size(),false);
	    
	    for(int i=0;i<dictionary.size();i++) {
	        for(int j=0;j<board.size();j++) {
	            for(int k=0;k<board[0].size();k++) {
	                if(board[j][k]==dictionary[i][0]) {
	                    if(dfs(board,dictionary[i],j,k,0)) {
	                        isFound[i]=true;
	                    }
 	                }
	            }
	        }
	    }
	    
	    vector<string> res;
	    for(int i=0;i<isFound.size();i++) {
	        if(isFound[i]) {
	            res.push_back(dictionary[i]);
	        }
	    }
	    sort(res.begin(),res.end());
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends