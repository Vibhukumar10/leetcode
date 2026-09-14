class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n,n),pse(n,-1);

        int res=0;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && st.top().second>heights[i]) {
                auto [idx,val]=st.top(); 
                st.pop();
                nse[idx]=i;
            }

            pse[i]=st.empty()?-1:st.top().first;

            st.push({i,heights[i]});
        }

        for(int i=0;i<n;i++) {
            res=max(res,(nse[i]-pse[i]-1)*heights[i]);
        }

        return res;
    }
};