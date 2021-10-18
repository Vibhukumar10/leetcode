class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    res+=mat[i][j];
                if((i+j)==n-1)
                    res+=mat[i][j];
            }
        }
        if(n%2==1)
            res-=mat[n/2][n/2];
        return res;
    }
};