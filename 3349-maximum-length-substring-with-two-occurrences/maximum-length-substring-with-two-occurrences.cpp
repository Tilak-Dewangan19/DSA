class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        unordered_map<char, int>mpp;
        int ans = INT_MIN;
       
        for(int j =0; j<s.size(); j++){
            mpp[s[j]]++;
            while(mpp[s[j]]> 2){
                mpp[s[i]]--;
                i++;
            }
        ans = max(ans, j-i+1);
        }
        return ans;
    }
};