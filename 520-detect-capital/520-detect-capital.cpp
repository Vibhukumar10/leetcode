class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        if(n==1) return true;
        if(word[0]>='A' && word[0]<='Z')
        {
            bool caps=false;
            if((word[1]<='Z' && word[1]>='A'))
                caps=true;
            for(int i=2;i<n;i++)
            {
                if(!caps && !(word[i]<='z' && word[i]>='a'))
                    return false;
                if(caps && !(word[i]<='Z' && word[i]>='A'))
                    return false;
            }
            return true;
        }
        else
        {
            for(int i=1;i<n;i++)
                if(!(word[i]<='z' && word[i]>='a'))
                    return false;
            return true;
        }
        return true;
    }
};