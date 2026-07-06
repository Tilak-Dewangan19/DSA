class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
       

        vector<int> range;
        int maxRange = 0;

        for (int num : nums) {

            int x = num;
            int smallest = 9;
            int largest = 0;

            if (x == 0) {
                smallest = largest = 0;
            }

            while (x > 0) {
                int digit = x % 10;
                smallest = min(smallest, digit);
                largest = max(largest, digit);
                x /= 10;
            }

            int diff = largest - smallest;
            range.push_back(diff);
            maxRange = max(maxRange, diff);
        }

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (range[i] == maxRange)
                sum += nums[i];
        }

        return sum;
    }
};
        
    