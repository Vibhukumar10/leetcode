class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> cars;

        for(int i=0;i<n;i++) {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.rbegin(),cars.rend());

        int res=0;
        stack<double> st;
        for(int i=0;i<n;i++) {
            double time=(double)(target-cars[i].first)/cars[i].second;
            if(!st.empty() && st.top()>=time) {
                continue;
            }
            st.push(time);
        }

        return st.size();
    }
};