class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        stack<int>st;
        
        for(auto x:pushed)
        {
            st.push(x);
            while(!st.empty() && st.top()==popped[j])
            {
                j++;
                st.pop();
            }
            
        }
        if(j==popped.size())
            return true;
        return false;
        
    }
};