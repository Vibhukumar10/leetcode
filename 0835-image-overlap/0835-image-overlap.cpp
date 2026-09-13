class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> v1,v2;

        int n=img1.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(img1[i][j]==1) {
                    v1.push_back({i,j});
                }
                if(img2[i][j]==1) {
                    v2.push_back({i,j});
                }
            }
        }

        map<pair<int,int>,int> mp;

        for(int i=0;i<v1.size();i++) {
            for(int j=0;j<v2.size();j++) {
                int p1x=v1[i].first;
                int p2x=v2[j].first;
                int p1y=v1[i].second;
                int p2y=v2[j].second;
                mp[{p1x-p2x,p1y-p2y}]++;
            }
        }

        int res=0;
        for(auto it:mp) {
            res=max(res,it.second);
        }

        return res;
    }
};