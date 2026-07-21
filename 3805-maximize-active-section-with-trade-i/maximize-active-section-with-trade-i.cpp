class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n = s.size();
        int tot1 = 0;
        for(auto& c : s){
            if(c == '1') tot1++;

        }
        vector<pair<char, int>> blocks;

        for(auto& c : s){
            if(blocks.empty() || blocks.back().first != c){
                blocks.push_back({c,1});
            }
            else{
                blocks.back().second++;
            }
        }
        int ans = tot1;

        for(int i =1; i< blocks.size()-1; i++){
            if(blocks[i].first== '1' && blocks[i-1].first == '0' && blocks[i+1].first == '0'){
                    ans = max(ans, tot1+ blocks[i-1].second + blocks[i+1].second);
            }
        }

        return ans;
    }
};