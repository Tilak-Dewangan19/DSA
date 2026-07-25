class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i =0;
        int cnt = m;
        int len = INT_MAX;
        int start = 0;
     unordered_map<char, int>mp;
     for(auto& c : t){
        mp[c]++;
     }
        for(int j =0; j<n; j++){
           if(mp[s[j]]> 0){
            cnt--;
           }
           mp[s[j]]--;

           while(cnt ==0){
            if(j - i + 1 < len){
                len = j - i + 1;
                start = i;
                
            }
            mp[s[i]]++;
            if(mp[s[i]] > 0){
                cnt++;
             
            }
               i++;
           }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};