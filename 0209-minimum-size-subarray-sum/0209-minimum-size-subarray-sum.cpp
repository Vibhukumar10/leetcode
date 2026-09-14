class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currSum=0;

        int start=0,res=INT_MAX;
        for(int end=0;end<nums.size();end++) {
            currSum+=nums[end];

            while(currSum>=target) {
                res=min(res,end-start+1);
                currSum-=nums[start];
                start++;
            }

        }

        return res==INT_MAX?0:res;
    }
};