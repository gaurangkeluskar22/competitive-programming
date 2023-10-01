class Solution {
public:
    void f(int n, vector<vector<int>>& edges) {
        vector<vector<long long>> dp(n, vector<long long>(n, INT_MAX));

        for (int i = 0; i < n; i++) dp[i][i] = 0;

        for (auto edge : edges) {
            int i = edge[0];
            int j = edge[1];
            int wt = edge[2];

            dp[i][j] = dp[j][i] = wt; // Assuming the graph is undirected.
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][k] < INT_MAX && dp[k][j] < INT_MAX)
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        
    }
};
