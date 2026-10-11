class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res=0,n=nums.size();
        for(int i=0;i<n;i++) {
            int idx=i+1;
            if(n%idx==0) {
                res+=nums[i]*nums[i];
            }
        }
        return res;
    }
};