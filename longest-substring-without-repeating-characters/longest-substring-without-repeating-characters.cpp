class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int s=0,e=0,n=str.length(),res=1;
        
        if(n==0)
            return 0;
        
        unordered_map<char,int> freq;
        
        while(e<n)
        {
            if(freq[str[e]]<1)
            {
                res=max(res,e-s+1);
                freq[str[e]]++;
                e++;
            }
            else
            {
                freq[str[s]]--;
                s++;
            }
        }
        
        
        return res;
    }
};