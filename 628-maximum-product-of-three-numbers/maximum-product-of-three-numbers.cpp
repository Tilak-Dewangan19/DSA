class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // int n = nums.size();
        // int maxi = INT_MIN;
        // for(int i =0; i<n; i++){
        //     int j = i+1;
        //     int k = n-1;
        //     while(j < k){
        //         int m = nums[i]* nums[j]* nums[k];
        //         maxi = max(maxi, m);

        //     }
        //     j++;
        //     k--;

        // }
        // return maxi;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m1 = nums[n-1]* nums[n-2]* nums[n-3];
        int m2 = nums[0]*nums[1] * nums[n-1];

        return max(m1, m2);
    }
};