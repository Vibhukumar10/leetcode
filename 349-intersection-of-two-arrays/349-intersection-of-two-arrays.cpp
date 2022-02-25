class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end()),res;
        for(int x:nums2)
        {
            if(s.find(x)!=s.end())
                res.insert(x);
        }
        vector<int> ans;
        for(auto it=res.begin();it!=res.end();it++)
            ans.push_back(*it);
        
        return ans;
    }   
};