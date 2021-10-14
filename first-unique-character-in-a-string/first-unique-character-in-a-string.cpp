class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> letter(26,0);
        for(int i=0;i<s.length();i++)
            letter[s[i]-'a']++;
        
        for(int i=0;i<s.length();i++)
            if(letter[s[i]-'a'] == 1)
                return i;
        
        return -1;
    }
};