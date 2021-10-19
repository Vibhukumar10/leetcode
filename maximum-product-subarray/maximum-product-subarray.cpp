class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();

        int minVal=arr[0];
        int maxVal=arr[0];

        int maxProd=arr[0];

        for(int i=1;i<n;i++)
        {
            if(arr[i]<0)
                swap(maxVal,minVal);

            minVal=min(arr[i],minVal*arr[i]);
            maxVal=max(arr[i],maxVal*arr[i]);

            maxProd=max(maxProd,maxVal);
        }
        return maxProd;
    }
};