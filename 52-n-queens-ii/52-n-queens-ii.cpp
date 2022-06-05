class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,1},{1,-1},{1,0},{-1,0},{-1,-1},{-1,1}};
    
    bool isValid(vector<vector<int>> curr,int n,int r,int c) {
        for(int i=0;i<8;i++) {
            int dupr=r;
            int dupc=c;
            while(dupr>=0 && dupc>=0 && dupr<n && dupc<n) {
                if(curr[dupr][dupc]==1) {
                    return false;
                }
                dupr+=dir[i].first;
                dupc+=dir[i].second;
            }
        }
        return true;
    }
    void NQueens(int &res,vector<vector<int>> curr,int n,int col) {
        if(col==n) {
            res++;
            return;
        }
        for(int i=0;i<n;i++) {
            if(isValid(curr,n,i,col)) {
                curr[i][col]=1;
                NQueens(res,curr,n,col+1);
                curr[i][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int res=0;
        vector<vector<int>> curr(n,vector<int> (n,0));
        NQueens(res,curr,n,0);
        return res;
    }
};