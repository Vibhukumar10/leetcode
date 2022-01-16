class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res=0,curr=0;
        int n=seats.size();
        for(int i=0;i<n;i++)
        {
            if(seats[i]==0)
                curr++;
            else
            {
                res=max(res,curr);
                curr=0;
            }
        }
        res=max(res,curr);
        
        int left=0;
        int right=0;
        if(seats[0]==0)
        {
            int i=0;
            while(seats[i]!=1)
            {
                i++;
            }
            left=i;
        }
        
        if(seats[n-1]==0)
        {
            int i=n-1;
            int total=0;
            while(seats[i]!=1)
            {
                i--;
                total++;
            }
            right=total;
        }
        
        if(res%2==0) 
            res=res/2;
        else
            res=res/2+1;
        
        int ans=max(res,max(left,right));
        return ans;
    }
};