class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        
        
        int l=0,r=n1;
        while(l<=r)
        {
            int i1=l+(r-l)/2;
            int i2=(n1+n2+1)/2 - i1;
            
            int left1 = (i1==0) ? INT_MIN : nums1[i1-1];
            int right1 = (i1==n1) ? INT_MAX : nums1[i1];
            int left2 = (i2==0) ? INT_MIN : nums2[i2-1];
            int right2 = (i2==n2) ? INT_MAX : nums2[i2];
            
            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2==0)
                    return (double) (max(left1,left2) + min(right1,right2)) / 2.0;
                else
                    return (double) max(left1,left2);
            }
            else if(left1>right2)
                r=i1-1;
            else
                l=i1+1;
        }
        return 0;
    }
};