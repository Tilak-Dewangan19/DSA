class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int count = 0;
        vector<int> copy;
        for(auto i : heights){
            copy.push_back(i);
        }
        sort(copy.begin(), copy.end());
        for(int i = 0; i<n; i++){
            if(heights[i] != copy[i]){
                count++;
            }
        }

        return count;
    }
};