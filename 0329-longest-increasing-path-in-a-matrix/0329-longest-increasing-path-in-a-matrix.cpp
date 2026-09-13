class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int r, int c,
            vector<vector<int>>& dp) {

        // Already calculated
        if(dp[r][c] != -1)
            return dp[r][c];

        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = 1;  // Current cell itself

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            // Valid cell + strictly increasing
            if(nr >= 0 && nr < rows &&
               nc >= 0 && nc < cols &&
               matrix[nr][nc] > matrix[r][c]) {

                ans = max(ans, 1 + dfs(matrix, nr, nc, dp));
            }
        }

        dp[r][c] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        int ans = 0;

        // Every cell can be a starting point
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                ans = max(ans, dfs(matrix, r, c, dp));
            }
        }

        return ans;
    }
};