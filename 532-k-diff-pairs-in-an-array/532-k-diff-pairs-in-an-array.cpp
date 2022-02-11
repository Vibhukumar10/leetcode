class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
            return 0;
        
        int res=0;
        
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        
        
        for(auto it:freq)
        {
            if(k==0)
            {
                if(it.second > 1)
                    res++;
            }
            
            else if(freq.find(it.first + k)!=freq.end())
                res++;
        }
        return res;
    }
};