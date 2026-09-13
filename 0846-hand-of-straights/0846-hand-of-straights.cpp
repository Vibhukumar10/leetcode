class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        unordered_map<int,int> freq;
        for(int num:hand) {
            freq[num]++;
        }

        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto &it:freq) {
            pq.push(it.first);
        }

        while(!pq.empty()) {
            int first=pq.top();
            for(int i=first;i<first+groupSize;i++) {
                if(freq.find(i)==freq.end()) {
                    return false;
                }
                freq[i]--;
                if(freq[i]==0) {
                    freq.erase(i);
                    if(i!=pq.top()) {
                        return false;
                    } else {
                        pq.pop();
                    }
                }
            }
        }

        return true;
    }
};

// 1,2,2,3,3,4,6,7,8