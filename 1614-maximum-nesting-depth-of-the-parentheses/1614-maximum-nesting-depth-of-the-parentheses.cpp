class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int res=0;

        for(char c:s) {
            if(c=='(') {
                st.push(c);
            } else if(c==')') {
                res=max(res,(int)st.size());
                st.pop();
            }
        }

        return res;
    }
};