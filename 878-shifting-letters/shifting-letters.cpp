class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
           int tot = 0;

        for(int i = n-1; i>=0; i--){
            tot = (tot + shifts[i]) % 26;

            s[i] = 'a'+(s[i] - 'a'+tot)%26;
        }
        return s;
    }
};