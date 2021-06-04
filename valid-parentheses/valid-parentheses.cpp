class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> together;
        together[']'] = '[';
        together[')'] = '(';
        together['}'] = '{';
        for(int i = 0 ; i<s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if(!st.empty() && together[s[i]] == st.top())
                    st.pop();
                else
                    return false;
            }    
        }
        return st.empty();
    }
};