class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=0;i<n;i++) {
            int currMax=INT_MIN,currMin=INT_MAX;
            for(int j=0;j<=i;j++) {
                currMax=max(currMax,nums[j]);
            }
            for(int l=i;l<n;l++) {
                currMin=min(currMin,nums[l]);
            }
            if(currMax-currMin<=k) {
                return i;
            }
        }

        return -1;
    }
};