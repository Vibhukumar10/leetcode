class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%2==0) {
                sum+=nums[i];
            }
        }
        
        for(vector<int> v:queries) {
            int val=v[0];
            int i=v[1];
            if((abs(nums[i])%2==0 && abs(val)%2==0)) {
                sum+=val;
                res.push_back(sum);
            } else if((abs(nums[i])%2==1 && abs(val)%2==1)) {
                sum+=val+nums[i];
                res.push_back(sum);
            } else if(abs(nums[i])%2==0 && abs(val)%2==1) {
                sum-=nums[i];
                res.push_back(sum);
            } else {
                res.push_back(sum);
            }
            nums[i]+=val;
        }
        
        return res;
    }
};