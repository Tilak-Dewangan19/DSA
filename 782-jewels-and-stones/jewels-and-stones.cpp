class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>s;
        for(auto& c : jewels){
            
            s.insert(c);
        }
        int cnt = 0;
        for(int i =0; i< stones.size(); i++){
        if(s.find(stones[i]) != s.end()){
                cnt++;
        }
        }
        return cnt;
    }
};