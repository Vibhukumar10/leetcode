class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int x:nums)
            mp[x]++;
        for(auto p:mp)
            if(p.second==2)
                res.push_back(p.first);
        
        return res;
    }
};