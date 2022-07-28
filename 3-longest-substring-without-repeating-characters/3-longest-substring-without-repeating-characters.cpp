class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos=-1;int ans=1;
        unordered_map<char,int>mp;
        if(s.size() == 0){
            return 0;
        }
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) == mp.end() || mp[s[i]]<pos ) {
                ans = max(ans, i - pos);  
            }
            else { 
                pos = mp[s[i]];
            }
            mp[s[i]] = i;
        }
        return ans;

        }
  
};