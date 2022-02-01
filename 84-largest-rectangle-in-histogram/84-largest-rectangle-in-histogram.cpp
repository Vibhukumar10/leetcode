class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==1)
            return heights[0];
        
        int rSmall[n],lSmall[n];
        
        rSmall[n-1]=n;
        lSmall[0]=-1;
        
        stack<int> s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            // int res=i+1;
            // while(res<n && heights[i]<=heights[res])
            //     res++;
            while(!s.empty() && heights[i]<=heights[s.top()])
                s.pop();
            rSmall[i]=s.empty() ? n:s.top();
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        s.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && heights[i]<=heights[s.top()])
                s.pop();
            lSmall[i]=s.empty() ?-1:s.top();
            s.push(i);
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<rSmall[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<lSmall[i]<<" ";
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            int l=lSmall[i], r=rSmall[i];                
            res=max(res,(r-l-1)*heights[i]);
        }
        return res;
    }
};