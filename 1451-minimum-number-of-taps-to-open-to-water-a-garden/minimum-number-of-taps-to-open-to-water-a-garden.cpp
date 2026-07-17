class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<int> reach(n + 1, 0);

        // reach[left] = farthest right endpoint
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            reach[left] = max(reach[left], right);
        }

        int taps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i <= n; i++) {

            if (i > farthest)
                return -1;

           

            // if (i == currEnd) {
            //     if (currEnd == n)
            //         break;
            if(i> currEnd ){
                taps++;
                currEnd = farthest;
            }
             farthest = max(farthest, reach[i]);
        }

        return taps;
    }
};