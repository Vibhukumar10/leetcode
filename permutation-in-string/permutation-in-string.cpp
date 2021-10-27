class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(int i=0;i<s1.length();i++)
        {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        
        for(int i=s1.length();i<s2.length();i++)
        {
            if(mp1==mp2)
                return true;
            
            mp2[s2[i]]++;
            mp2[s2[i-s1.length()]]--;
            if(mp2[s2[i-s1.length()]]==0)
                mp2.erase(s2[i-s1.length()]);            
        }
        return mp1==mp2;        
    }
};