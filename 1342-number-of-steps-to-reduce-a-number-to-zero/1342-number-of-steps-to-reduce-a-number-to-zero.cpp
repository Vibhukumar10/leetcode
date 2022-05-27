class Solution {
public:
    int numberOfSteps(int num) {
        if(num<3) return num;
        
        int memo[num+1];
        
        memo[0]=0;
        memo[1]=1;
        
        for(int i=2;i<=num;i++) {
            if(i%2==0) {
                memo[i]=1+min(memo[i-1],memo[i/2]);
            } else {
                memo[i]=1+memo[i-1];
            }
        }
        return memo[num];
    }
};