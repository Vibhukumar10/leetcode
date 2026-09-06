class Solution {
public:
    map<pair<int,int>,int> memo;
    int dfs(string &s,string &t,int i,int j) {
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        if(memo.find({i,j})!=memo.end()) {
            return memo[{i,j}];
        }

        if(s[i]==t[j]) {
            return memo[{i,j}]=dfs(s,t,i+1,j)+dfs(s,t,i+1,j+1);
        } else {
            return memo[{i,j}]=dfs(s,t,i+1,j);
        }

        return 0;
    }
    int numDistinct(string s, string t) {
        return dfs(s,t,0,0);
    }
};