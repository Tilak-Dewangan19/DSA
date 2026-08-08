class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> ans;

        // suf[j] = index in word1 where word2[j] can start
        // in the earliest possible exact subsequence.
        vector<int> suf(m, -1);

        int p = n - 1;

        for (int j = m - 1; j >= 0; j--) {

            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }

            if (p < 0)
                break;

            suf[j] = p;
            p--;
        }

        // Greedily choose the smallest possible index.
        p = 0;
        bool mismatchUsed = false;

        for (int j = 0; j < m; j++) {

            while (p < n) {

                // Exact match
                if (word1[p] == word2[j]) {
                    ans.push_back(p);
                    p++;
                    break;
                }

                // Try using this position as the one mismatch
                if (!mismatchUsed) {

                    bool canFinish = true;

                    if (j + 1 < m) {

                        // Need to match word2[j+1...]
                        // exactly after p.
                        if (suf[j + 1] == -1 ||
                            suf[j + 1] <= p) {
                            canFinish = false;
                        }
                    }

                    if (canFinish) {
                        ans.push_back(p);
                        p++;
                        mismatchUsed = true;
                        break;
                    }
                }

                p++;
            }

            // Could not select an index for word2[j]
            if (ans.size() != j + 1)
                return {};
        }

        return ans;
    }
};