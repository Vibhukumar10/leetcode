class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {     
        vector<int> sor=nums;
        sort(sor.begin(),sor.end());
        
        int res=0,l=0,r=nums.size()-1;
        while(l<nums.size() && sor[l]==nums[l]) {
            l++;
        }
        
        while(r>=0 && sor[r]==nums[r]) {
            r--;
        }
        
        if(r<0 || l>nums.size()) {return 0;} return (r-l+1);
    }
};