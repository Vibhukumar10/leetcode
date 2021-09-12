class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
                s2.push_back(tolower(s[i]));
            else if(isdigit(s[i]))
                s2.push_back(s[i]);
        }
        stack<int> st;
        for(char c:s2)
            st.push(c);
        string s3;
        while(!st.empty())
        {
            s3.push_back(st.top());
            st.pop();
        }
        return s2==s3;
    }
};