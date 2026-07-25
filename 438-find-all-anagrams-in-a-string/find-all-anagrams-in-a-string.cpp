class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0;
        int cnt = p.size();
        vector<int>ans;
        unordered_map<char, int>mp;
        for(auto & c : p){
            mp[c]++;

        }
        for(int j =0; j< s.size(); j++){
            if(mp[s[j]] > 0){
                cnt--;

            }
            mp[s[j]]--;
           if(j-i+1 > p.size()){
            if(mp[s[i]] >= 0){
                cnt++;
            }
            mp[s[i]]++;
            i++;
           }
            if(j-i+1 == p.size() && cnt == 0){
                ans.push_back(i);
            }

        }
        return ans;
    }
};