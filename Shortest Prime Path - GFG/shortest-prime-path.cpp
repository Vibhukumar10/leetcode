// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    
    int solve(int Num1,int Num2)
    {   
      //code here
        vector<bool> isPrime(10000,true);
        for(int i=2;i*i<10000;i++) {
            if(isPrime[i]) {
                for(int j=i*i;j<10000;j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        
        if(Num1==Num2) return 0;
        
        vector<bool> vis(10000,false);
        queue<int> q;
        q.push(Num1);
        vis[Num1]=true;
        int res=0;
        
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int temp=q.front();
                q.pop();
                
                if(temp==Num2) return res;
                
                for(int k=0;k<4;k++) {
                    if(k==0) {
                        for(int j=1;j<=9;j++) {
                            string s=to_string(temp);
                            s[0]=j+'0';
                            int num=stoi(s);
                            // cout<<num;
                            if(isPrime[num] && !vis[num]) {
                                q.push(num);
                                vis[num]=true;
                            }
                        }
                    } else {
                        for(int j=0;j<=9;j++) {
                            string s=to_string(temp);
                            s[k]=j+'0';
                            int num=stoi(s);
                            if(isPrime[num] && !vis[num]) {
                                q.push(num);
                                vis[num]=true;
                            }
                        }
                    }
                }
            }
            res++;
        }
    }
};


// { Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}  // } Driver Code Ends