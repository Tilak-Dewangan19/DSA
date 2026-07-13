class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        vector<int> pos[26];

        // Store indices of every character
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        int ans = 0;

        for (string &word : words) {

            int prevIndex = -1;
            bool ok = true;

            for (char ch : word) {

                auto &v = pos[ch - 'a'];

                auto it = lower_bound(v.begin(), v.end(), prevIndex + 1);

                if (it == v.end()) {
                    ok = false;
                    break;
                }

                prevIndex = *it;
            }

            if (ok) ans++;
        }

        return ans;
    }
};