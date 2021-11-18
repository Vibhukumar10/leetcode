class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> freq(nums.size()+1,false);
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]=true;
        vector<int> res;
        for(int i=1;i<=nums.size();i++)
        {
            if(!freq[i])
                res.push_back(i);
        }
        return res;
    }
};