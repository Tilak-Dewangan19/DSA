class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int>freq;
        for(auto& it : candyType){
            freq[it];
        }
        int distinct= freq.size();
        int caneat = candyType.size()/2;

        return min(distinct, caneat);
        
    }
};