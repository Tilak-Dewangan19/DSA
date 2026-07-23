class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
       
        int s1 = 0;
        for(auto &it : aliceSizes){ 
            s1 = s1 + it;

        }
        int s2 = 0;
        for(auto &it : bobSizes){ 
            s2 = s2 + it;

        }
         unordered_set<int>st;
            st.insert(bobSizes.begin(), bobSizes.end());
        for(auto& x : aliceSizes){
            int y = x + (s2-s1)/2;
           

            if(st.find(y) != st.end()){
               return {x, y};

            }
        }
        return {};
    }
};