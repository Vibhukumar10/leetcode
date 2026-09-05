class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> lMax(n),rMin(n);
        lMax[0]=nums[0];
        rMin[n-1]=nums[n-1];

        for(int i=1;i<n;i++) {
            lMax[i]=max(lMax[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--) {
            rMin[i]=min(rMin[i+1],nums[i]);
        }

        for(int i=0;i<n;i++) {
            if(lMax[i]-rMin[i]<=k) {
                return i;
            }
        }

        return -1;
    }
};