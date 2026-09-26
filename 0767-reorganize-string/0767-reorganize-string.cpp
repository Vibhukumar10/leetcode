class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(char c:s) {
            freq[c]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto it:freq) {
            pq.push({it.second,it.first});
        }

        pair<int,char> tmp;

        string res="";
        while(!pq.empty()) {
            auto [f,c]=pq.top();
            pq.pop();

            res+=c;
            f--;

            if(tmp.first>0 && tmp.second!=c) {
                pq.push(tmp);
            }
            
            tmp={f,c};
        }

        if(tmp.first>0) {
            return "";
        }

        return res;
    }
};