class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,1},{1,-1},{1,0},{-1,0},{-1,-1},{-1,1}};
    
    bool isValid(vector<string> curr,int n,int r,int c) {
        for(int i=0;i<8;i++) {
            int rdup=r;
            int cdup=c;
            while(rdup>=0 && cdup>=0 && rdup<n && cdup<n) {
                if(curr[rdup][cdup]=='Q') {
                    return false;                    
                }       
                rdup=dir[i].first+rdup;
                cdup=dir[i].second+cdup;
            }
        }
        return true;
    }
    
    void NQueens(vector<vector<string>> &res,vector<string> curr,int col,int n) {
        if(col==n) {
            res.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++) {
            if(isValid(curr,n,i,col)) {
                curr[i][col]='Q';
                NQueens(res,curr,col+1,n);
            }
            curr[i][col]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n,string(n,'.'));
        
        NQueens(res,curr,0,n);
        return res;
    }
};