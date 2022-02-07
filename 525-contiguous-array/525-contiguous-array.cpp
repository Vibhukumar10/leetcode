class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0,n=nums.size();
        if(nums.size()==1)
            return 0;
        unordered_map<int,int> m;
        m.insert({0,-1});
        
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i]==1?1:-1;
            if(m.count(curr))
                res=max(res,i-m[curr]);
            else
                m.insert({curr,i});
        }
        return res;
    }
};