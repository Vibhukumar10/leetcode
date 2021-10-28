class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0]+nums[1]+nums[3],n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int l=0,r=n-1;
            while(l<r)
            {
                if(l==i) {l++;continue;}
                if(r==i) {r--;continue;}
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                    return target;
                
                else if(target<sum) {
                    if(abs(res-target) > abs(sum-target))
                        res=sum;
                    r--;
                }
                else
                {
                    if(abs(res-target) > abs(sum-target))
                        res=sum;
                    l++;
                }
            }
        }
        
        return res;        
    }
};