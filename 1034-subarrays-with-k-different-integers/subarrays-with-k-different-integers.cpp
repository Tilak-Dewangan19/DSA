#include <map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int l = 0, res = 0;
        map<int, int> freq; 

        for (int r = 0; r < nums.size(); r++) {
            if (freq[nums[r]] == 0) k--; 
            freq[nums[r]]++;

            while (k < 0) { 
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]); 
                    k++;
                }
                l++;
            }

            res += (r - l + 1);
        }
        return res;
    }
};
