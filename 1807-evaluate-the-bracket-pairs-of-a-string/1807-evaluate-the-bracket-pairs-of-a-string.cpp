class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res="";

        unordered_map<string,string> mp;

        for(vector<string> str:knowledge) {
            mp[str[0]]=str[1];
        }

        // int i=0;
        // while(i<s.size()) {
        //     if(s[i]=='(') {
        //         string curr="";
        //         i++;
        //         while(i<s.size() && s[i]!=')') {
        //             curr+=s[i];
        //             i++;
        //         }
        //         if(mp.find(curr)!=mp.end()) {
        //             res+=mp[curr];
        //         } else {
        //             res+="?";
        //         }
        //     } else {
        //         if(s[i]==')') {
        //             i++;
        //             continue;
        //         }
        //         res+=s[i];
        //         i++;
        //     }
        // }

        bool isBrace=false;
        string brace="";
        for(char c:s) {
            if(c=='(') {
                isBrace=true;
            } else if(c==')') {
                if(mp.find(brace)!=mp.end()) {
                    res+=mp[brace];
                } else {
                    res+="?";
                }
                isBrace=false;
                brace="";
            } else {
                if(isBrace) {
                    brace+=c;
                    continue;
                } else {
                    res+=c;
                }
            }
        }

        return res;
    }
};