class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        
        set<vector<int>> v;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-1;i++)
        {
            int l=i+1,r=n-1;
            while(l<=r)
            {
                // if(l==i)
                //     l++;
                // else if(r==i)
                //     r--;
                // else
                // {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    if(i!=l && i!=r &&l!=r)
                    {
                        v.insert({nums[i],nums[l],nums[r]});
                    }
                    l++;r--;
                    // vector<int> v(3);
                    // v[0]=nums[i];
                    // v[1]=nums[l];
                    // v[2]=nums[r];
                    // res.push_back(v);
                    // l++;r--;
                }
                else if(sum>0)
                    r--;
                else
                    l++;
                // }
            }
        }
        
        for(auto i=v.begin();i!=v.end();i++)
            res.push_back(*i);
        
        return res;
    }
};