class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num:nums) {
            st.insert(num);
        }

        int res=0;
        for(auto it:st) {
            if(st.find(it-1)==st.end()) {
                int start=it;
                int count=0;
                while(st.find(start)!=st.end()) {
                    count++;
                    start++;
                    res=max(res,count);
                }
            }
        }

        return res;
    }
};