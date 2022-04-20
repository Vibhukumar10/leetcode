class Solution {
public:
    int winner(vector<int> &nums,int l,int r,int turn) {
        if(l==r) {
            return turn*nums[l];
        }
        
        int a=turn*nums[l] + winner(nums,l+1,r,-turn);
        int b=turn*nums[r] + winner(nums,l,r-1,-turn);
        
        return turn*max(turn*a,turn*b);        
    }
    bool PredictTheWinner(vector<int>& nums) {
        return winner(nums,0,nums.size()-1,1) >=0;
    }
};