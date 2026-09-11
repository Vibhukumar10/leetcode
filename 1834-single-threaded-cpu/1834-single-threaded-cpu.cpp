class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // {enqueueTime, processingTime, originalIndex}
        vector<tuple<long long, long long, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Sort by enqueue time
        sort(v.begin(), v.end());

        // {processingTime, originalIndex}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            // If no task is available, jump to the next task's enqueue time
            if (pq.empty()) {
                time = max(time, (long long)get<0>(v[i]));
            }

            // Add every task that has arrived
            while (i < n && get<0>(v[i]) <= time) {
                pq.push({get<1>(v[i]), get<2>(v[i])});
                i++;
            }

            // Pick:
            // 1. Smallest processing time
            // 2. Smallest index if tied
            auto [processTime, index] = pq.top();
            pq.pop();

            ans.push_back(index);
            time += processTime;
        }

        return ans;
    }
};