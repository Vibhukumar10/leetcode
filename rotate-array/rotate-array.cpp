class Solution {
public:
    
    void reverse(vector<int> &arr, int l, int r)
    {
        while(l<r)
        {
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size())
            k=k%nums.size();
        reverse(nums, 0,nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};