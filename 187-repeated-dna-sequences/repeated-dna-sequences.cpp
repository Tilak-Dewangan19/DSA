class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        int n  = s.size();
        unordered_map<string, int>mp;
        for(int i =0; i< n-9;i++){
            string sub = s.substr(i, 10);
            mp[sub]++;
            if(mp[sub] == 2){
                ans.push_back(sub);

            }
        }
        return ans;
        
    }
};