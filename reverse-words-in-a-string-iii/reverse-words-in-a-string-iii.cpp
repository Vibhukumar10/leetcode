class Solution {
public:
    void reverse(string &s,int l,int r)
    {
        while(l<=r)
        {
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    
    string reverseWords(string s) {
        int l=0,r=0,n=s.length();
        while(l<n && r<n)
        {
            while(r<n && s[r]!=' ')
                r++;
            
            if(r==n-1)
            {
                reverse(s,l,r);
                break;
            }
            else
            {
                reverse(s,l,r-1);
                r++;
                l=r;
            }
        }
        return s;
    }
};