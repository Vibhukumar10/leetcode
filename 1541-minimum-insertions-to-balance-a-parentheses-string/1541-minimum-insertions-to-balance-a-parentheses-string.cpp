class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int res = 0;

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                st.push('(');
                i++;
            } else {
                // Consume )) as one closing pair.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i += 2;
                } else {
                    res++; // Insert missing ')'
                    i++;
                }

                // Match the closing pair with an opening '('.
                if (st.empty()) {
                    res++; // Insert missing '('
                } else {
                    st.pop();
                }
            }
        }

        return res + 2 * st.size();
    }
};