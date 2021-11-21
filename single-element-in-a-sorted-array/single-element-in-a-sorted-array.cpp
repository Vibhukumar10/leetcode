class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==nums[m+1]) m=m-1;
            
            if((m-l+1)%2==0) l=m+1;
            
            else r=m;
        }
        return nums[l];
    }
};