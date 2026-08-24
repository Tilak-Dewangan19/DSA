class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i = 1; i<n ;i++){
        //     if(nums[i] == nums[i-1]){
        //         return true;
        //     break;
        //     }
        // }
        // return false;
        unordered_map<int, int>freq;
        for(auto& i: nums){
            freq[i]++;
        }
        for(auto&c : freq){
            if(c.second >= 2){
                return true;
                break;
            }

        }
        return false;
    }
};