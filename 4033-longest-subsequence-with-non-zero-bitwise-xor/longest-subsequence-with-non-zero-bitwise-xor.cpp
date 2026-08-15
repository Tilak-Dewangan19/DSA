class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;

        for(auto& i : nums){
            x = x ^ i;
        }
        if(x != 0){
            return n;
        }
        for(auto & i : nums){
            if(i != 0){
                return n-1;
            }
        }
       
        return 0;
    }
};