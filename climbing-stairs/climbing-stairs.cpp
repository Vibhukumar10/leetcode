int memo[46]={0};
class Solution {
public:
    int climbStairs(int n) {
        if(memo[n]==0)
        {
            if(n<3)
                memo[n]=n;
            else
                memo[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return memo[n];
    }
};