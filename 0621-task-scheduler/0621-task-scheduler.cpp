class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char task:tasks) {
            freq[task]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto it:freq) {
            pq.push({it.second,it.first});
        }

        int res=0;
        while(!pq.empty()) {
            int slots=n+1;
            vector<pair<int,char>> remaining;

            while(slots>0 && !pq.empty()) {
                auto [f,c]=pq.top();
                pq.pop();

                f--;
                res++;
                slots--;

                if(f) {
                    remaining.push_back({f,c});
                }
            }

            for(auto it:remaining) {
                pq.push(it);
            }

            if(!pq.empty()) {
                res+=slots; 
            }
        }

        return res;
    }
};