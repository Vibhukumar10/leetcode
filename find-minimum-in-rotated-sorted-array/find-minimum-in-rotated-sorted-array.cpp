class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        
        if(nums[l]<=nums[r])
            return nums[0];
        
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>nums[m+1])
                return nums[m+1];
            
            if(nums[m-1]>nums[m])
                return nums[m];
            
            if(nums[m]>nums[l])
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};