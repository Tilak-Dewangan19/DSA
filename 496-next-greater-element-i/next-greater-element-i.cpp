class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            for(int i =0; i< nums1.size(); i++){
                int ge = -1;
                for(int j =0; j< nums2.size(); j++){
                    if(nums1[i] == nums2[j]){
                        
                        for(int k = j+1; k< nums2.size(); k++){
                            if(nums1[i]< nums2[k]){
                             ge = nums2[k];
                             break;
                        }
                        }
                        break;                
                    }
                }
                nums1[i] = ge;
            }

      return nums1;
    }
    
};