class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>mini(26, INT_MAX);
        for(auto &i : words){
            vector<int>count(26, 0);
            for(auto &it : i){
                count[it-'a']++;
               
            }
            for(int it =0; it<26;it++){
                    mini[it] = min(mini[it], count[it]);
            }
        }
             
        vector<string> ans;

        for (int i = 0; i < 26; i++) {
            while (mini[i]-- ) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;

        
       

        
    }
};