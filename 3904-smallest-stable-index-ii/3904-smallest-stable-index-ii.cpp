class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        deque<int> dq;
        for(int i=0;i<n;i++) {
            while(!dq.empty() && nums[dq.back()] > nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        int currMax=nums[0],currMin=nums[dq.front()];
        if(currMax-currMin<=k) return 0;

        for(int i=1;i<n;i++) {
            currMax=max(currMax,nums[i]);
            if(i-1==dq.front()) {
                dq.pop_front();
            }
            currMin=nums[dq.front()];
            if(currMax-currMin<=k) return i;
        }

        return -1;
    }
};