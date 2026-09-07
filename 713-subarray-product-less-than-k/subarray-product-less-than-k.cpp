class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long i =0, j = 0, prod = 1, ans = 0;
        if(k == 0) return 0;
        for(; j< nums.size(); j++){
            prod*=nums[j];
            while(i<=j && prod >= k){
                prod = prod/nums[i];
                i++;
            }
                ans += j-i+1;
            
        }
        return ans;
    }
};