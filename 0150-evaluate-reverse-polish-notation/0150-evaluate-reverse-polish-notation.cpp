class Solution {
public:
    bool isOperand(string s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens) {
            if(isOperand(s)) {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();

                if(s=="+") {
                    st.push(b+a);
                } else if(s=="-") {
                    st.push(b-a);
                } else if(s=="*") {
                    st.push(b*a);
                } else {
                    st.push(b/a);
                }
            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};