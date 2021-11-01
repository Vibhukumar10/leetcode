class Solution {
public:
    int helper(vector<int> &arr,int n)
    {
        int res=1;
        vector<int> lis(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                    lis[i]=max(lis[i],lis[j]+1);
            }
        }
        
        for(int i=0;i<n;i++)
            res=max(res,lis[i]);
        
        return res;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums,nums.size());
    }
};