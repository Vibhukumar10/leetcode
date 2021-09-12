class Solution {
public:
    bool isPalindrome(string str) {
        
       string s;
        
        for(char c : str)
            if(isalnum(c)) 
                s += isalpha(c) and isupper(c) ? tolower(c) : c;
        
        return equal(begin(s), end(s), rbegin(s));
    }
};