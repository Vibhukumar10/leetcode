// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

class Node {
    public:
    int data;
    Node *left,*right;
    Node(int x) {
      data=x;
      left=right=NULL;
    }
};


class Solution{
    public:
    int index;
    unordered_map<int,int> mp;
    
    Node *construct(int preorder[],int l,int r) {
        if(l>r) {
            return NULL;
        }
        
        int rootVal=preorder[index++];
        Node *root=new Node(rootVal);
        
        if(mp.find(rootVal)==mp.end()) {
            return NULL;
        }
        
        root->left=construct(preorder,l,mp[rootVal]-1);
        root->right=construct(preorder,mp[rootVal]+1,r);
        
        return root;
    }
    
    void post(Node *root,vector<int> &pos) {
        if(!root) {
            return;
        }
        
        post(root->left,pos);
        post(root->right,pos);
        pos.push_back(root->data);
    }
    
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
        if (preorder[0] != postorder[N-1])
	        return false;
	        
        index=0;
        for(int i=0;i<N;i++) {
            mp[inorder[i]]=i;
        }
        
    	Node *root=construct(preorder,0,N-1);
    	vector<int> pos;
        post(root,pos);
    	
    	for(int i=0;i<N;i++) {
    	    if(pos[i]!=postorder[i]) return false;
    	}
    	
    	return true;
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
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends