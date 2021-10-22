class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {        
        int l=0,r=nums.size()-1;
        
        vector<int> res(r+1,0);
        int i=r;
        while(l<=r)
        {
            if(abs(nums[l])>=abs(nums[r]))
            {
                res[i--]=nums[l]*nums[l];
                l++;
            }
            else
            {
                res[i--]=nums[r]*nums[r];
                r--;   
            }
        }
        return res;
    }
};