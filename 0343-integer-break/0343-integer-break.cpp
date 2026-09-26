class Solution {
public:
    unordered_map<int,int> memo;
    int solve(int n) {
        if (n == 1) {
            return 1;
        }

        if(memo.find(n)!=memo.end()) {
            return memo[n];
        }

        int best = 0;

        for (int i = 1; i < n; i++) {
            best = max({
                best,
                i * (n - i),
                i * solve(n - i)
            });
        }

        return memo[n]=best;
    }

    int integerBreak(int n) {
        return solve(n);
    }
};