class Solution {
public:
    int houseRobber(vector<int> &nums) {
        int n=nums.size();
        if(n==0) {
            return 0;
        } else if(n==1) {
            return nums[0];
        }
        
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        
        for(int i=3;i<=n;i++) {
            int pick = nums[i-1] + dp[i-2];
            int np = dp[i-1];
            dp[i] = max(pick,np);
        }
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==0) {
            return 0;
        } else if(nums.size()==1) {
            return nums[0];
        }
        
        vector<int> f,l;
        for(int i=0;i<nums.size();i++) {
            if(i<nums.size()-1) {
                l.push_back(nums[i]);
            }
            if(i>=1) {
                f.push_back(nums[i]);
            }
        }
        
        int fir = houseRobber(l);
        int las = houseRobber(f);
        
        return max(fir,las);        
    }
};