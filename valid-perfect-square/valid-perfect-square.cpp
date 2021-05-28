class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int s=sqrt(num);
        if(num==s*s)
            return true;
        return false;
    }
};