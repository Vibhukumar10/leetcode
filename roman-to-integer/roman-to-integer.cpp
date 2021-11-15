class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map;
        map.insert({'I',1});
        map.insert({'V',5});
        map.insert({'X',10});
        map.insert({'L',50});
        map.insert({'C',100});
        map.insert({'D',500});
        map.insert({'M',1000});
        
        int res=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(i+1<n && map[s[i]]<map[s[i+1]])
            {
                res+=map[s[i+1]]-map[s[i]];
                i++;
            }            
            else
                res+=map[s[i]];
        }
        return res;
    }
};