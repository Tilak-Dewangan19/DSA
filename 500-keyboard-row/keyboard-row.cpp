class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        string row;
        vector<string> ans;

        for (auto& it : words) {
            string temp = it;
            for (char &c : temp) {
                c = tolower(c);
            }

            if (row1.find(temp[0]) != string::npos) {
                row = row1;
            } else if (row2.find(temp[0]) != string::npos) {
                row = row2;

            } else {
                row = row3;
            }
            bool xyz = true;
            for (auto& c : temp) {
                if (row.find(c) == string::npos) {
                    xyz = false;
                    break;
                }
            }
            if (xyz) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};