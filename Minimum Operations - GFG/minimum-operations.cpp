// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int helper(int s,int e) {
        if(s==e) {
            return 0;
        }
        
        if(s>e) {
            return INT_MAX;
        }
        
        return 1+min(helper(s+1,e),helper(s*2,e));
    }
  
    int minOperation(int n) {
        //code here.
        // return 1+helper(1,n);
        int memo[n+1];
        memo[0]=0;
        memo[1]=1;
        memo[2]=2;
        
        for(int i=3;i<=n;i++) {
            if(i%2==0)
                memo[i]=1+min(memo[i-1],memo[i/2]);
            else memo[i]=1+memo[i-1];
        }
        return memo[n];
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends