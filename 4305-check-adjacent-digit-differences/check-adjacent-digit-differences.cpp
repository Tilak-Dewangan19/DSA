class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            int j = i + 1;
            if (abs(s[i] - s[j]) > 2) {
                return false;
            }
        }
        return true;
    }
};