class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int res=0;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=ans[res][1])
            {
                ans[res][0]=min(ans[res][0],intervals[i][0]);
                ans[res][1]=max(ans[res][1],intervals[i][1]);                
            }
            else
            {
                ans.push_back(intervals[i]);
                res++;
            }
        }
        return ans;
    }
};