class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        // TLE:
        vector<pair<int,int>> v;
//         for(int i=0;i<n;i++)
//             v.push_back({temperatures[i],i});
        
//         for(int i=0;i<n;i++)
//         {
//             int j=i;
//             while(j<n && v[j].first<=v[i].first)
//                 j++;
            
//             if(j==n)
//                 res.push_back(0);
//             else
//                 res.push_back(j-i);
//         }
        stack<int> s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && temperatures[s.top()]<=temperatures[i])
                s.pop();
            
            if(!s.empty())
                res[i]=s.top()-i;
            
            s.push(i);
        }
        return res;        
    }
};