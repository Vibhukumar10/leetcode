class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<char> adj[beginWord.size()];
        unordered_set<string> st;
        unordered_set<string> vis;
        
        for(string str:wordList) {
            st.insert(str);
        }
        
        for(int i=0;i<beginWord.size();i++) {
            for(string s:wordList) {
                    adj[i].insert(s[i]);
            }
        }
        
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int count=0;
        
        while(!q.empty()) {
            int sz=q.size();
            count++;
            for(int i=0;i<sz;i++) {
                string temp=q.front(); q.pop();
                
                // cout<<temp<<" ";
                if(temp==endWord) {
                    return count;
                }
                
                
                for(int j=0;j<temp.size();j++) {
                    for(auto it:adj[j]) {
                        char c=temp[j];
                        temp[j]=it;
                        if(st.find(temp)!=st.end() && vis.find(temp)==vis.end()) {
                            q.push(temp);
                            vis.insert(temp);
                        }
                        temp[j]=c;
                    }
                }
            }
            // cout<<"\n";
        }
        return 0;
    }
};