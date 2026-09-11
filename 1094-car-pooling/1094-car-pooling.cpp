class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1]==b[1]? a[2]<b[2] : a[1] < b[1];
        });

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int currPass=0,i=0,n=trips.size();

        while(i<n) {
            pq.push({trips[i][2],trips[i][0]});
            currPass+=trips[i][0];
            int currPos=trips[i][1];

            while(!pq.empty()) {
                auto [end,pass]=pq.top();
                if(currPos >= end) {
                    currPass-=pass;
                    pq.pop();
                } else {
                    break;
                }
            }

            if(currPass>capacity) {
                return false;
            }

            i++;
        }

        return true;
    }
};