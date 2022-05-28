// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const int M=1e9+7;

class Solution
{
    public:
    long long res;
    //Function to count the number of ways in which frog can reach the top.
    long long helper(long long s,int n,vector<long long> &memo) {
        if(memo[s]==-1) {   
            if(s==n) {
                memo[s]=1;
            }
            else {
                for(int i=1;i<=3;i++) {
                    if((s+i)<=n) {
                        res=(res+helper(s+i,n,memo))%M;
                    }
                }
                memo[s]=res%M;
            }
        }
        return memo[s]%M;
    }
    
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> memo(n+1,-1);
        // res=0;
        // return helper(0,n,memo);
        memo[0]=1;
        memo[1]=1;
        memo[2]=2;
        
        for(int i=3;i<=n;i++) {
            memo[i]=(memo[i-1]%M + memo[i-2]%M + memo[i-3]%M)%M;
        }
        return memo[n];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends