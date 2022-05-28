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
	   // return helper(mem,str1,str1.length(),str2,str2.length());
	   int n=str1.length(),m=str2.length();
	   
	   for(int i=0;i<=n;i++) {
	       for(int j=0;j<=m;j++) {
	           if(i==0||j==0) {
	               mem[i][j]=i+j;
	           } else {
	               if(str1[i-1]==str2[j-1]) {
	                   mem[i][j]=mem[i-1][j-1];
	               } else {
	                   mem[i][j]=1+min(mem[i-1][j],mem[i][j-1]);
	               }
	           }
	       }
	   }
	   return mem[n][m];
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