class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         int n = nums.size();

        // Calculate the total number of subsets (2^n) using bitwise shift
        int subsets = 1 << n;

        // Vector to store all subsets
        vector<vector<int>> ans;

        // Iterate through all numbers from 0 to 2^n - 1
        for (int num = 0; num < subsets; num++) {
            // Temporary vector to hold the current subset
            vector<int> subset;

            // Iterate through each bit of the number
            for (int i = 0; i < n; i++) {
                // If the ith bit is set, include nums[i] in the subset
                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            // Add the constructed subset into the result
            ans.push_back(subset);
        }

        // Return all subsets
        return ans;
    }
};