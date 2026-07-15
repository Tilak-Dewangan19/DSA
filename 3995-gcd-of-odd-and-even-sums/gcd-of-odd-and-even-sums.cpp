class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven = 0;
        int sumodd = 0;

        for(int i = 1; i<= n; i++){
            sumeven += 2*i;
            sumodd += 2*i -1;
        }
   
      return gcd(sumodd, sumeven);
    }
};