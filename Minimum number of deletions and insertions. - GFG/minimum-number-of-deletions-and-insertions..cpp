// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int helper(vector<vector<int>> &mem,string s1,int n,string s2,int m) {
	    if(mem[n][m]==-1) {
    	    if(n==0 || m==0) return mem[n][m]=(n+m);
    	    
    	    if(s1[n-1]==s2[m-1]) {
    	        return mem[n][m]=helper(mem,s1,n-1,s2,m-1);
    	    } else {
    	        return mem[n][m]=1+min(helper(mem,s1,n-1,s2,m),helper(mem,s1,n,s2,m-1));
    	    }
	    }
	    return mem[n][m];
	}
	
	int minOperations(string str1, string str2) { 
	    // Your code goes here
	    vector<vector<int>> mem(str1.length()+1,vector<int> (str2.length()+1,-1));
	    return helper(mem,str1,str1.length(),str2,str2.length());
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends