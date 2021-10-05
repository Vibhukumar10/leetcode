class Solution {
public:
    int minPartitions(string n) {
        int maxm=INT_MIN;
        for(char c:n)
            maxm=max(maxm,c-'0');
        return maxm;
    }
};