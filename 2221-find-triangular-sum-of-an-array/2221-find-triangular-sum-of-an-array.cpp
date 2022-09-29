class Solution {
public:
    int triangularSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
        return arr[0];
        vector<int> temp;
        for(int i=0;i<n-1;i++)
        temp.push_back((arr[i]+arr[i+1])%10);
        return triangularSum(temp); 
    }
};