class Solution {
public:
    string simplifyPath(string path) {
        path=path+"/";
        int n=path.length();
        stack<string> st;
        
        stringstream ss(path);
        
        while(ss)
        {
            string dir;
            getline(ss,dir,'/');
            if(dir.size()==0 || dir=="." || (st.empty() && dir=="..")) continue;
            else if(!st.empty() && dir=="..") st.pop();
            else st.push(dir);
        }
        
        if(st.empty()) return "/";
        
        string res;
        while(!st.empty())
        {
            res=st.top()+res;
            res="/"+res;
            st.pop();
        }
        return res;
    }
};