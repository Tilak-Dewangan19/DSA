class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        long long totsum = 0;
        
        for(long long i = n-1; i>= 0; i--){
           
              if(mul>=1) totsum+= 1LL*nums[i] * mul;
              else{
                totsum +=nums[i];
              }
               mul--;
               k--;
                if(k == 0) break;
            }
           
        
        return totsum;
        
    }
};