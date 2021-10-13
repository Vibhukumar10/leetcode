class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int avg=0,res=0,sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
            avg+=arr[i];
        }
        
        avg=sum/k;
        if(avg>=threshold)
            res++;
        
        for(int i=k;i<arr.size();i++)
        {
            sum+=arr[i]-arr[i-k];
            avg=sum/k;
            if(avg>=threshold)
                res++;
        }
        return res;        
    }
};