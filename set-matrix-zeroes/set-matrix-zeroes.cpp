class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i<i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]==0)
                    v.push_back(make_pair(i,j));
        
        for(pair<int,int> p : v)
        {
            int row=p.first;
            int col=p.second;
            for(int i=0;i<n;i++)
                matrix[i][col]=0;
            
            for(int j=0;j<m;j++)
                matrix[row][j]=0;
        }        
    }
};