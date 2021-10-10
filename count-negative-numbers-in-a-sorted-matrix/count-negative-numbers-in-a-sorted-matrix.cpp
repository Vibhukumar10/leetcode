class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res=0;
        for(auto row:grid)
        {
            int l=0,r=row.size()-1;
            while(l<=r)
            {
                if(row[r]>=0)
                    break;
                else
                {
                    res++;
                    r--;
                }
            }
        }
        return res;
    }
};