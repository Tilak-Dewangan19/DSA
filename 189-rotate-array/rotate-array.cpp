// class Solution {
// public:
//     // void rotate(vector<int>& nums, int k) {
//     //     int n = nums.size();
//     //     k = k % n;

//     //     vector<int> temp(k);

//     //     for(int i = n-k; i < n; i++) {
//     //         temp[i-(n-k)] = nums[i];
//     //     }

//     //     for(int i = n-k-1; i >= 0; i--) {
//     //         nums[k+i] = nums[i];
//     //     }

//     //     for(int i = 0; i < k; i++) {
//     //         nums[i] = temp[i];
//     //     }
//     // }
//       void reverseArray(vector<int>& nums, int start, int end) {
//         while (start < end) {
//             swap(nums[start], nums[end]);
//             start++;
//             end--;
//         }
//     }

//     // Function to rotate array left or right by k steps
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();

//         // Edge case: empty or no rotation
//         // if (n == 0 || k == 0) return nums;

//         // Normalize k
//         k = k % n;

//         // if (direction == "right") {
//             // Step 1: Reverse the whole array
//             reverseArray(nums, 0, n - 1);

//             // Step 2: Reverse first k elements
//             reverseArray(nums, 0, k - 1);

//             // Step 3: Reverse remaining n-k elements
//             reverseArray(nums, k, n - 1);
//             //  return nums;
//         } 
//         // else if (direction == "left") {
//         //     // Step 1: Reverse first k elements
//         //     reverseArray(nums, 0, k - 1);

//         //     // Step 2: Reverse remaining n-k elements
//         //     reverseArray(nums, k, n - 1);

//         //     // Step 3: Reverse the whole array
//         //     reverseArray(nums, 0, n - 1);
//         // }

       
    
// };
class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        // Reverse the whole array
        reverseArray(nums, 0, n - 1);

        // Reverse first k elements
        reverseArray(nums, 0, k - 1);

        // Reverse the remaining elements
        reverseArray(nums, k, n - 1);
    }
};