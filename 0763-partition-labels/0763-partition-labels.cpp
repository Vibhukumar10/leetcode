class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) {
            mp[s[i]]=i;
        }

        vector<int> res;
        int partitionSize=0, partitionEnd=0;

        for(int i=0;i<s.size();i++) {
            partitionSize++;
            partitionEnd=max(partitionEnd,mp[s[i]]);
            if(i==partitionEnd) {
                res.push_back(partitionSize);
                partitionSize=0;
            }
        }
        
        return res;
    }
};