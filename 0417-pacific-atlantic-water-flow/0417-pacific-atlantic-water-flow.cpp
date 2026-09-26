class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        queue<pair<int,int>> qp,qa;
        vector<vector<bool>> visp(heights.size(),vector<bool> (heights[0].size(),false));
        vector<vector<bool>> visa=visp;

        for(int i=0;i<heights.size();i++) {
            for(int j=0;j<heights[0].size();j++) {
                if(i==0 || j==0) {
                    qp.push({i,j});
                    visp[i][j]=true;
                }

                if(i==heights.size()-1 || j==heights[0].size()-1) {
                    qa.push({i,j});
                    visa[i][j]=true;
                }
            }
        }

        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};

        while(!qp.empty()) {
            int sz=qp.size();
            while(sz--) {
                auto [x,y]=qp.front();
                qp.pop();

                for(int i=0;i<4;i++) {
                    int nx=x+dx[i];
                    int ny=y+dy[i];

                    if(nx>=0 && nx<heights.size() && ny>=0 && ny<heights[0].size()) {
                        if(heights[nx][ny] >= heights[x][y] && !visp[nx][ny]) {
                            qp.push({nx,ny});
                            visp[nx][ny]=true;
                        }
                    }
                }
            }
        }

        while(!qa.empty()) {
            int sz=qa.size();
            while(sz--) {
                auto [x,y]=qa.front();
                qa.pop();

                for(int i=0;i<4;i++) {
                    int nx=x+dx[i];
                    int ny=y+dy[i];

                    if(nx>=0 && nx<heights.size() && ny>=0 && ny<heights[0].size()) {
                        if(heights[nx][ny] >= heights[x][y] && !visa[nx][ny]) {
                            qa.push({nx,ny});
                            visa[nx][ny]=true;
                        }
                    }
                }
            }
        }

        for(int i=0;i<heights.size();i++) {
            for(int j=0;j<heights[0].size();j++) {
                if(visp[i][j] && visa[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};