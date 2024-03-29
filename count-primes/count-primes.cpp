class Solution {
public:
    
    bool isprime(int n)
    {
        if(n==1)
            return false;
        if(n==2||n==3)
            return true;
        if(n%3==0||n%2==0)
            return false;
        for(int i=5;i*i<=n;i+=6)
        {
            if(n%i==0||n%(i+2)==0)
                return false;
        }
        return true;
    }
    
    int countPrimes(int n) 
    {
        if(n==0||n==1)
            return 0;
        int res=0;
        for(int i=2;i<n;i++)
        {
            if(isprime(i))
                res++;
        }
        return res;
    }
};