class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> check;

        while(true) {
            int currSum=0;

            int currNum=n;
            while(currNum) {
                int digit=currNum%10;
                currSum+=digit*digit;
                currNum=currNum/10;
            }
            cout<<currSum<<endl;

            if(check.find(currSum)!=check.end()) {
                return false;
            }
            if(currSum==1) {
                return true;
            }
            check.insert(currSum);
            n=currSum;
        }

        return false;
    }
};