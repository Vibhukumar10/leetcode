class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        queue<string> q;

        unordered_set<string> set;

        for(string str:wordList) {
            set.insert(str);
        }

        if(set.find(endWord)==set.end()) {
            return 0;
        }

        q.push(beginWord);
        if(set.find(beginWord)!=set.end()) {
            set.erase(beginWord);
        }

        int level=0;
        while(!q.empty()) {
            level++;
            int sz=q.size();
            while(sz--) {
                string curr=q.front();
                q.pop();

                if(curr==endWord) {
                    return level;
                }
                
                // string temp=curr;
                for(int i=0;i<n;i++) {
                    for(int j=0;j<26;j++) {
                        char c=curr[i];

                        curr[i]='a'+j;
                        if(set.find(curr)!=set.end()) {
                            q.push(curr);
                            set.erase(curr);
                        }
                        curr[i]=c;
                    }
                }
            }
        }

        return 0;
    }
};