class Solution {
public:
    int maxProduct(int n) {
       int largest = 0;
       int secla = 0;
       while(n > 0){
       int digit = n % 10;
       if(digit > largest){
        secla = largest;
        largest = digit;
       }
       else if(digit > secla){
        secla = digit;
       }
       n/= 10;
       }
       return largest * secla;
    }
};