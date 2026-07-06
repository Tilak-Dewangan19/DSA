class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        // for(int i = 0; i< nums1.size(); i++){
        //     for(int j =0; j< nums2.size(); j++){
        //         if(nums1[i] == nums2[j]){
        //                 temp.push_back(nums1[i]);
        //                 nums2[j] = -1;
        //                 break;
        //         }
        //     }
        // }
        unordered_map<int, int> mpp;
        for(int i : nums1){
            mpp[i]++;
        }
        for(int i : nums2){
            if(mpp[i] > 0) {
                temp.push_back(i);
                mpp[i]--;
            }
        }
        return temp;
    }
};