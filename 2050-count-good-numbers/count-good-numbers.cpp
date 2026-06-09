class Solution {
    private:
    const long long mod = 1e9 + 7;
    long long myPow(long long x, long long n) {
        x = x % mod;
        long long N = n;
        if(N< 0){
            x = 1/x;
            N = -N;        }
            long long ans = 1;
            while(N>0){
                if(N%2 == 1){
                    ans = (ans * x) % mod;
                }
                x = (x *x) % mod ;
                N= N/2;
            }
            return ans;
    }
        
public:
    int countGoodNumbers(long long n) {
      
        long long even = (n+1)/2;
        long long odd = (n/2);
        long long res = (myPow(5, even)* myPow(4, odd)) % mod;
        return res;

        
    }
};