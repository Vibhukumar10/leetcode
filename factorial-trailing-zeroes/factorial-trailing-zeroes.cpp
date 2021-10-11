class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        int divisor=5;
        while(n/divisor>0)
        {
            res+=n/divisor;
            divisor*=5;
        }
        return res;
    }
};