class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

    
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            res = (res + (arr[i] * leftCount % MOD) * rightCount % MOD) % MOD;
        }

        return (int)res;
    }
};
