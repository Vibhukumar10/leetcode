class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator it;
        for(int i=0 ; i<nums.size() ; i++)
        {
               if(m.find(target-nums[i])!=m.end())
                 {
                      v.push_back(i);
                      it=m.find(target-nums[i]);
                      v.push_back(it->second);
                      break;
                 }
              else{
                     m.insert({nums[i],i});
                }
        }
        return v;
    }
};