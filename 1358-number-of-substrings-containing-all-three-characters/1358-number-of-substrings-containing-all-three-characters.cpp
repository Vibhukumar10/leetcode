class Solution {
public:
    int numberOfSubstrings(string s) {
        if(s.length()<3)
            return 0;
        
        unordered_map<char,int> m;
        
        int res=0,l=0,r=0;
        while(r<s.length())
        {
            m[s[r]]++;
            if(m.size()<3)
                r++;
            else if(m.size()==3)
            {
                res+=(s.size()-r);
                m[s[l]]--;
                if(m[s[l]]==0)
                    m.erase(s[l]);
                l++;
                m[s[r]]--;
            }
        }
        return res;
    }
};