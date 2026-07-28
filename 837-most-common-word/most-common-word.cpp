class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>ban(banned.begin(), banned.end());
        unordered_map<string, int>mpp;
        string word = "";

        for(auto& i : paragraph){
            if(isalpha(i)){
                word+=tolower(i);
            }
            else{
                if(!word.empty()){
                    if(ban.find(word) == ban.end()){
                        mpp[word]++;
                      
                    }
                      word ="";
                }
                

                }

            }
            if(!word.empty() && !ban.count(word)){
                mpp[word]++;
            }
            int maxi =0;
            string ans;

            for(auto& it : mpp){
                if(it.second> maxi){
                    maxi =it.second;
                    ans =it.first;
                }
            }
        return ans;
       
        
    }
};