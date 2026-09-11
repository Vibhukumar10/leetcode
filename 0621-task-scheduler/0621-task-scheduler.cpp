class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;

        for(char task:tasks) {
            freq[task]++;
        }

        priority_queue<int> pq;
        
        for(auto it:freq) {
            pq.push(it.second);
        }

        int time=0;

        while(!pq.empty()) {
            int slots=n+1;
            vector<int> remaining;

            while(slots>0 && !pq.empty()) {
                int f=pq.top(); pq.pop();

                f--;
                if(f>0) {
                    remaining.push_back(f);
                }

                time++;
                slots--;
            }

            for(int task:remaining) {
                pq.push(task);
            }

            if(!pq.empty()) {
                time+=slots;
            }
        }

        return time;
    }
};