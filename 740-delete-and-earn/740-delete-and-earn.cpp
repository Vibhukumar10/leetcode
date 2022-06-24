class Solution {
public:
    int maxPoints(vector<int> v,map<int,int> f) {
        vector<int> dp(v.size(),0);
        dp[0]=v[0]*f[v[0]];
        for(int i=1;i<v.size();i++) {
            int pick = v[i]*f[v[i]];
            if((v[i-1]+1)!=v[i]) {
                pick+=dp[i-1];
            } else if(i>1) {
                pick+=dp[i-2];
            }
            int npick = dp[i-1];
            dp[i]=max(pick,npick);
        }
        
        return dp[v.size()-1];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> f;
        for(int i=0;i<nums.size();i++) {
            f[nums[i]]++;
        }
        
        vector<int> v;
        for(auto it:f) {
            v.push_back(it.first);
        }
        
        return maxPoints(v,f);
    }
};