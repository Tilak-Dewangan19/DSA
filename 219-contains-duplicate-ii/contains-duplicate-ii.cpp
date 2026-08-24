class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i<n; i++){
        if(mpp.find(nums[i]) != mpp.end()){
            if(abs(i- mpp[nums[i]]) <= k){
                return true;
            }
            
        }
        mpp[nums[i]] = i;
        }
        // for(int i = 0; i<n; i++){
        //     for(int j =i+1; j<n; j++){
        //         if(nums[i]==nums[j] 
        //         && abs(i-j)<=k){
        //             return true;
        //             break;

        //         }
        //     }
        // }
        return false;
    }
};