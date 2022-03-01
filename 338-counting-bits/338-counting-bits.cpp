class Solution {
public:
    int getSet(int i)
    {
        int res=0;
        while(i)
        {
            i=i&(i-1);
            res++;
        }
        return res;
    }
    
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<n+1;i++)
        {
            res.push_back(getSet(i));
        }
        return res;
    }
};