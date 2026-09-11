class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<int> res;

        // {enqueueTime, processingTime, index}
        vector<tuple<int, int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Sort by enqueue time
        sort(v.begin(), v.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> ans;

        long long time = get<0>(v[0]);
        int i = 0;

        while(i<n || !pq.empty()) {
            if(pq.empty()) {
                time=max(time, (long long)get<0>(v[i]));
            }

            while(i<n && get<0>(v[i])<=time) {
                pq.push({get<1>(v[i]),get<2>(v[i])});
                i++;
            }

            auto [processingTime,currIdx] = pq.top(); pq.pop();
            time+=processingTime;
            res.push_back(currIdx);
        }

        return res;
    }
};