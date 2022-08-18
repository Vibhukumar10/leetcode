class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int x:arr) {
            mp[x]++;
        }
        
        int res=0;
        
        priority_queue<int> pq;
        for(auto it:mp) {
            pq.push(it.second);
        }
        
        int curr=0;
        while(curr<n/2) {
            res++;
            curr+=pq.top();
            if(!pq.empty()) pq.pop();
        }
        
        return res;
    }
};