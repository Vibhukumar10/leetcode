// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        vector<int> adj[31];
        for(int i=1;i<=29;i++) {
            adj[i].push_back(i+1);
        }
        adj[30].push_back(-1);
        
        int count=0;
        while(count<N) {
            adj[arr[2*count]].pop_back();
            adj[arr[2*count]].push_back(arr[2*count+1]);
            count++;
        }
        
        
        // for(int i=1;i<=30;i++) {
        //     cout<<i<<": ";
        //     for(int v:adj[i]) {
        //         cout<<v<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        // cout<<"\n\n";
        
        queue<pair<int,int>> q;
        q.push({1,0});
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++) {
                int pos=q.front().first;
                int ch=q.front().second;
                q.pop();
                
                // if(pos==30) {
                //     return ch;
                // }
                
                for(int j=1;j<=6;j++) {
                    int newPos=pos+j;
                    if(newPos <= 30) {
                        if(newPos==30) {
                            return ch+1;
                        } else {
                            if(adj[newPos][0]!=newPos+1) {
                                q.push({adj[newPos][0],ch+1});
                            } else {
                                q.push({newPos,ch+1});
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends