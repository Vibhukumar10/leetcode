class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<stones.size();i++) {
            pq.push({stones[i],i});
        }
        
        while(pq.size()>1) {
            int y=pq.top().first;
            int yi=pq.top().second;
            pq.pop();
            int x=pq.top().first;
            int xi=pq.top().second;
            pq.pop();
            if(x!=y) {
                pq.push({y-x,yi});
            }
        }
        
        return pq.size() == 0 ? 0 : pq.top().first;
    }
};