
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> mp(26, 0);

        for (char c : s1) {
            mp[c - 'a']++;
        }

        int i = 0;
        int cnt = n;

        for (int j = 0; j < m; j++) {
            if (mp[s2[j] - 'a'] > 0) {
                cnt--;
            }

            mp[s2[j] - 'a']--;

            if (j - i + 1 > n) {
                if (mp[s2[i] - 'a'] >= 0) {
                    cnt++;
                }

                mp[s2[i] - 'a']++;
                i++;
            }

            if (j - i + 1 == n && cnt == 0) {
                return true;
            }
        }

        return false;
    }
};
