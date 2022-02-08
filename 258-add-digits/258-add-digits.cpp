class Solution {
public:
    int sumDigits(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    
    int addDigits(int num) {
        if(num<10)
            return num;
        
        while(num>9)
        {
            num=sumDigits(num);    
        }
        return num;
    }
};