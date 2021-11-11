class Solution {
public:
//     int helper(vector<int> &arr,int n)
//     {
//         int res=1;
//         vector<int> lis(n,1);
        
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(arr[j]<arr[i])
//                     lis[i]=max(lis[i],lis[j]+1);
//             }
//         }
        
//         for(int i=0;i<n;i++)
//             res=max(res,lis[i]);
        
//         return res;
//     }
    
    int getCeil(int arr[],int l,int r,int x)
    {
        int res=r;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m]<x)
                l=m+1;
            
            else
            {
                res=min(res,m);
                r=m-1;
            }
        }
        return res;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // return helper(nums,nums.size());
        
        int n=nums.size();
        int tail[n],len=1;
        tail[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>tail[len-1])
            {
                tail[len]=nums[i];
                len++;
            }
            else
            {
                int idx=getCeil(tail,0,len-1,nums[i]);
                tail[idx]=nums[i];
            }
        }
        return len;
    }
};