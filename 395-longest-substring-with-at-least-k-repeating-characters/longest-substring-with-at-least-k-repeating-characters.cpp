class Solution {
public:
    int longestSubstring(string s, int k) {
        // if(s.size() < k)return 0;
        unordered_map<char, int>freq;

        for(auto& c : s){
            freq[c]++;
        }

        for(int i =0; i<s.size(); i++){
            if(freq[s[i]] < k ){
                string left = s.substr(0, i);
                string right = s.substr(i+1);

                return max(longestSubstring(left, k), longestSubstring(right, k));
            }
        }
        return s.size();
        
    }
};