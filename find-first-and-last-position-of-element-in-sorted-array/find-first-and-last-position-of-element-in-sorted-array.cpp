class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> res(2);
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==target)
            {
                while(nums[l]!=target)
                   l++;
                
                while(nums[r]!=target)
                   r--;
                
                res[0]=l;
                res[1]=r;
                return res;
            }
            else if(nums[m]<target)
                l=m+1;
            else
                r=m-1;
        }
        return {-1,-1};
    }
};