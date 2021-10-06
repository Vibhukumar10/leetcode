class Solution {
public:
    bool myComp(vector<int> a,vector<int> b)
    {
        return a[0] < b[0];
    }
    
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int res=0;
        for(int i=1;i<points.size();i++)
        {
            int curr=points[i][0]-points[i-1][0];
            res=max(res,curr);
        }
        return res;
    }
};