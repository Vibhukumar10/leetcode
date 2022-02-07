class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26,0),w(26,0);
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']++;
        }
        
        for(int i=0;i<t.length();i++)
        {
            w[t[i]-'a']++;
            if(w[t[i]-'a']>v[t[i]-'a'])
                return t[i];
        }
        return '0';
    }
};