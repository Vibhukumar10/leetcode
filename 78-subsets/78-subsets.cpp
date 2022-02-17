class Solution {
public:
    vector<int> getArray(int num,vector<int> nums)
    {
        vector<int> res;
        int index=nums.size()-1;
        while(num)
        {
            if(num&1 == 1)
            {
                res.insert(res.begin(),nums[index]);
            }
            index--;
            num=num>>1;
        }
        return res;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        
        for(int i=0;i<pow(2,n);i++)
        {
            vector<int> set=getArray(i,nums);
            res.push_back(set);
        }
        return res;
    }
};