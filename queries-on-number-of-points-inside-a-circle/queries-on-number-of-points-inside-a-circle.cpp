class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(vector<int> v:queries)
        {
            int x1=v[0];
            int y1=v[1];
            int r=v[2];
            int count=0;
            for(vector<int> p:points)
            {
                int x2=p[0];
                int y2=p[1];
                int dist=(pow(x2-x1,2)+pow(y2-y1,2));
                if(dist<=r*r)
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};