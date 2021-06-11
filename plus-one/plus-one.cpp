class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int i=digits.size()-1,carry=1;
        while(i>=0)
        {
            if(digits[i]+carry==10)
            {
                carry=1;
                digits[i--]=0;
            }
            else
            {
                digits[i]++;
                carry=0;
                break;
            }
        }
        if(carry)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};