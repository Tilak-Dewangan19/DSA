class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd = INT_MAX;
        int mineven = INT_MAX;

        for(auto& c : nums1){
            if(c%2 == 0){
                mineven = min(mineven, c);
            }
            else{
                minodd = min(minodd, c);
            }
        }
        if(mineven == INT_MAX){
            return true;
        }
        if(minodd == INT_MAX){
            return true;
        }
        return minodd < mineven;
        
    }
};