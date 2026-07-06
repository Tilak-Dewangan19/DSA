class Solution {
public:
    int longestPalindrome(string s) { 
        unordered_map<int, int> mpp; 
        int ans= 0;
        bool odd = 0;

        for(char c : s){
            mpp[c]++;

        }
        for(auto &it : mpp){
            if(it.second % 2 == 0){
                ans+=it.second;
            }
            else{
                ans+=it.second-1;
                odd =1;
            }
        }
        if(odd){
            ans++;
        }
        return ans;
        }
};