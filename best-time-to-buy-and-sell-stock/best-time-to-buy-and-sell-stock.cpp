class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> rMax(n,0);
        rMax[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int res=max(prices[i],rMax[i+1]);
            rMax[i]=res;
        }
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,rMax[i]-prices[i]);
        }
        return res;
        
    }
};