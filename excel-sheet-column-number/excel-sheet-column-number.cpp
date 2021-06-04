class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        int multiplier=1;
        int n=columnTitle.length();
        for(int i=0;i<columnTitle.length();i++){
            int value=columnTitle[i]-'A'+1;
            res+=(pow(26,--n)*value);
        }  
        return res;
    }
};