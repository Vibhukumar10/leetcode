class Solution {
public:
    int memo[1000][1000];
    int helper(string s1,string s2,int m,int n)
    {
        if(memo[m][n]==-1)
        {
            if(m==0)
                memo[m][n]=n;
            else if(n==0)
                memo[m][n]=m;
            else
            {
                if(s1[m-1]==s2[n-1])
                    memo[m][n]=helper(s1,s2,m-1,n-1);

                else
                    memo[m][n]=1+min(helper(s1,s2,m-1,n-1),min(helper(s1,s2,m-1,n),helper(s1,s2,m,n-1)));
            }
        }
        return memo[m][n];
    }
    
    int minDistance(string word1, string word2) {
        memset(memo,-1,sizeof(memo));
        return helper(word1,word2,word1.size(),word2.size());
    }
};