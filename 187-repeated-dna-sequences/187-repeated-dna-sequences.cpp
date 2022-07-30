class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10) return {};
        
        string sub = s.substr(0,10);
        unordered_map<string,int> mp;
        
        vector<string> res;
        mp[sub]++;
        
        for(int i=10;i<s.length();i++) {
            string a = sub.substr(1,9);
            a.push_back(s[i]);
            mp[a]++;
            sub=a;
        }
        
        for(auto it:mp) {
            if(it.second >= 2) {
                res.push_back(it.first);
            } 
        }
        
        return res;
    }
};