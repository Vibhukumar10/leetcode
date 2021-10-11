class Solution {
public:
    string reverseWords(string s) {
        string str,st;
        for(int i=0;i<s.length();i++) 
        {
            if(s[i]==' ') 
            {
                if(st.length()>0) 
                    str = st +" "+ str;
                st.clear();
            }
            else 
                st+=s[i];
        }
        if(st.length()>0) 
            str = st +" "+ str;
        str.pop_back();
        return str;
    }
};