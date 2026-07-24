class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        int cnt = 0;
        for (auto& c : words[0]) {
            if (isvowel(c))
                cnt++;
        }
        for (int i = 1; i < words.size(); i++) {
            int cnt1 = 0;
            for (auto& ch : words[i]) {

                if (isvowel(ch)) {
                    cnt1++;
                }
            }
            if (cnt1 == cnt) {
                reverse(words[i].begin(), words[i].end());
            }
        }

        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];

            if (i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};