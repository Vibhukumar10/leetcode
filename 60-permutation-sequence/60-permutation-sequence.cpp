class Solution {
public:
    void help(string s,int k,int l,int r) {
        if(l>r) {
            return;
        } 
        
        if(k==0) {
            return;
        }
        
        for(int i=r;i>=l;i--) {
            swap(s[i],s[r]);
            help(s,k-1,l,r-1);
            swap(s[i],s[r]);
        }
    }
    string getPermutation(int n, int k) {
        string s(n,'*');
        for(int i=1;i<=n;i++) s[i-1]=i+'0';
        // help(s,k,0,n-1);
        
        do {
            k--;
            if(k==0) {
                return s;
            }
        } while(next_permutation(s.begin(),s.end()));
        
        return s;
    }
};