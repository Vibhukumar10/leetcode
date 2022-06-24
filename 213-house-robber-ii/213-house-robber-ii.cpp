class Solution {
public:
    int f(vector<int> &nums) {
        int n=nums.size();
        if(n==1) {
            return nums[0];
        }
        int prev2=nums[0];
        int prev=max(nums[0],nums[1]);
        for(int i=2;i<n;i++) {
            int curr=max(prev2+nums[i],prev);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) {
            return nums[0];
        }
        vector<int> v1,v2;
        for(int i=0;i<n;i++) {
            if(i!=0) {
                v1.push_back(nums[i]);
            }
            if(i!=(n-1)) {
                v2.push_back(nums[i]);
            }
        }
        
        return max(f(v1),f(v2));        
    }
};