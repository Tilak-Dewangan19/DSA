class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        // Store value -> index
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // dp[i][j] = length of Fibonacci-like subsequence
        // ending with arr[i] and arr[j]
        vector<vector<int>> dp(n, vector<int>(n, 2));

        int ans = 0;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {

                // Previous number required
                int prev = arr[j] - arr[i];

                // prev must be smaller than arr[i]
                // (ensures its index is before i because array is strictly increasing)
                if (prev >= arr[i])
                    continue;

                if (index.find(prev) != index.end()) {
                    int k = index[prev];

                    dp[i][j] = dp[k][i] + 1;

                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans >= 3 ? ans : 0;
    }
};