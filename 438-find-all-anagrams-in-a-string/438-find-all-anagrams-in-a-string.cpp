class Solution {
public:   
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),m=p.length();
        int l=0,r=p.length()-1;
        
        vector<int> res;
        if(m>n)
            return res;
        
        vector<int> pattern(26,0);
        vector<int> window(26,0);
        
        for(int i=0;i<m;i++)
        {
            pattern[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        if(pattern==window) res.push_back(0);
        
        for(int i=m;i<n;i++)
        {
            window[s[i-m]-'a']--;
            window[s[i]-'a']++;
            if(pattern==window) res.push_back(i-m+1);
        }
        
        return res;
    }
};