class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        unordered_map<char,int> freq;
        freq['a']=a;
        freq['b']=b;
        freq['c']=c;

        priority_queue<pair<int,char>> pq;

        for(auto [c,f]:freq) {
            if(f>0)
                pq.push({f,c});
        }

        string res="";
        while(!pq.empty()) {
            auto [f,c]=pq.top(); pq.pop();

            int n=res.size();
            // can't take 
            if(n>1 && res[n-1]==c && res[n-2]==c) {
                if(pq.empty()) {
                    break;
                }
                auto [f2,c2]=pq.top(); pq.pop();
                res+=c2;
                f2--;
                if(f2>0) {
                    pq.push({f2,c2});
                }
                pq.push({f,c});
            } else {
                res+=c;
                f--;
                if(f>0) {
                    pq.push({f,c});
                }
            }
        }

        return res;
    }
};