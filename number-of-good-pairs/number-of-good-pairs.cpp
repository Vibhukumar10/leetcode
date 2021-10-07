class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> m;
        for(int x:nums)
            m[x]++;
        
        for(auto it:m)
        {
            if(it.second>1)
                res+=(it.second)*(it.second-1)/2;
        }
        return res;
    }
};