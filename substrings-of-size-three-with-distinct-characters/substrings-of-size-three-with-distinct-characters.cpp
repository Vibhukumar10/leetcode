class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<3;i++)
            m[s[i]]++;
        
        int res=0;
        if(m.size()==3)
            res=1;
        
        for(int i=3;i<s.length();i++)
        {
            m[s[i-3]]--;
            if(m[s[i-3]]==0)
                m.erase(s[i-3]);
            m[s[i]]++;
            
            if(m.size()==3)
                res++;
        }
        
        return res;
    }
};