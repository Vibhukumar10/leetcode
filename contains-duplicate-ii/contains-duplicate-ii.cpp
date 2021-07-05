class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                auto it=m.find(nums[i]);
                if(abs(it->second-i)<=k)
                    return true;
                else if(abs(it->second-i)>k)
                    m[nums[i]]=i;
            }
            m.insert({nums[i],i});
        }
        return false;
    }
};