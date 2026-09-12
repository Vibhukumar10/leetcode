class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);

        stack<int> st;
        st.push(0);

        for(int i=1;i<n;i++) {
            while(!st.empty() && temperatures[i]>temperatures[st.top()]) {
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};