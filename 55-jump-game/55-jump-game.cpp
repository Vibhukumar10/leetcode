class Solution {
public:
    bool canJump(vector<int>& nums) {
//         int n=nums.size();
        
//         if(nums[0]==0) {
//             return false;
//         }
        
//         vector<bool> dp(n+1,0);
//         dp[0] = true;
//         dp[1] = nums[0]==0 ? false : true;
        
//         for(int i=2;i<=n;i++) {
            
//         }
//         return dp[n];
        int tar=0;
        for(int i=0;i<nums.size();i++){
            if(tar<i){
                return false;
            }
            tar=max(tar,i+nums[i]);
        }
        return true;
    }
};