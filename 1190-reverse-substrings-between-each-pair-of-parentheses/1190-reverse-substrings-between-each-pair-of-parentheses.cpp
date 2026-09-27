class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(char c:s) {
            if(c=='(' || isalpha(c)) {
                st.push(c);
            } else {
                queue<char> tmp;
                while(!st.empty() && st.top()!='(') {
                    char tc=st.top();
                    st.pop();
                    tmp.push(tc);
                }
                if(st.top()=='(') {
                    st.pop();
                }
                while(!tmp.empty()) {
                    st.push(tmp.front());
                    tmp.pop();
                }
            }
        }

        string res="";
        while(!st.empty()) {
            res=st.top()+res;
            st.pop();
        }

        return res;
    }
};

// ["(", "u", "(", "love"]