class Solution {
public:
    string lower(string s) {
        for (char& c : s) {
            c = tolower(c);
        }
        return s;
    }
    string devowel(string s) {
        s =lower(s);
        for (char& c : s) {

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> cap;
        unordered_map<string, string> vowel;

        for (auto& w : wordlist) {
            exact.insert(w);

            string low = lower(w);
            if (cap.find(low) == cap.end()) {
                cap[low] = w;
            }
            string dev = devowel(w);
            if (vowel.find(dev) == vowel.end()) {
                vowel[dev] = w;
            }
        }
        vector<string> ans;

        for (auto& q : queries) {
            if (exact.find(q) != exact.end()) {
                ans.push_back(q);
                continue;
            }
            string low = lower(q);
            if (cap.find(low) != cap.end()) {
                ans.push_back(cap[low]);
                continue;
            }
            string dev = devowel(q);
            if (vowel.find(dev) != vowel.end()) {
                ans.push_back(vowel[dev]);
                continue;
            }
            ans.push_back("");
        }

        return ans;
    }
};