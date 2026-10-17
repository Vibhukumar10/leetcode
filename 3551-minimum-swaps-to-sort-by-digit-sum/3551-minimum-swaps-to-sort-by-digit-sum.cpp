class Solution {
public:
    static int getDigSum(int num) {
        int res=0;
        while(num) {
            res+=num%10;
            num=num/10;
        }
        return res;
    }

    int minSwaps(vector<int>& nums) {
        auto lambda = [](int num1, int num2) {
            int digSum1 = getDigSum(num1);
            int digSum2 = getDigSum(num2);

            if (digSum1 == digSum2) {
                return num1 < num2;
            }

            return digSum1 < digSum2;
        };

        vector<int> actual=nums;
        sort(actual.begin(),actual.end(),lambda);
        
        unordered_map<int,int> idx;
        for(int i=0;i<nums.size();i++) {
            idx[nums[i]]=i;
        }

        int res=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=actual[i]) {
                res++;

                int actualIdx=idx[actual[i]];

                swap(nums[i],nums[actualIdx]);
                idx[nums[i]]=idx[actual[i]];
                idx[nums[actualIdx]]=idx[nums[i]];
            }
        }

        return res;
    }
};

// 37  -> 0
// 100 -> 1