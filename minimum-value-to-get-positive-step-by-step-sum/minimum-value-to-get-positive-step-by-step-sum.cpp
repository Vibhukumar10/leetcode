class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++)
            nums[i]+=nums[i-1];
        
        int mini=INT_MAX;
        for(int x:nums)
            mini=min(mini,x);
        
        return (mini<0)? 1-mini : 1;
    }
};