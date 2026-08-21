class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1 ={nums[0]};
        vector<int>arr2 = {nums[1]};
        for(int i = 2; i<n; i++){
            if(arr1.back()> arr2.back()){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        vector<int>arr;
        for(int x : arr1){
        arr.push_back(x);
        }
        for(int y : arr2){
        arr.push_back(y);
        }
        return arr;
        
    }
};