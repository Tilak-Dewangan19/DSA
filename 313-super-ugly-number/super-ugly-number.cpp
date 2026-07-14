class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long>ugly(n);
        ugly[0] = 1;

        vector<int>ptr(k, 0);

        for(int i = 1; i< n; i++){
                long long next = LLONG_MAX;
                for(int j = 0; j < k; j++){
                    next = min(next, ugly[ptr[j]] * primes[j]);
                }
                ugly[i] = next;

                for(int j = 0; j <k ;j++){
                    if(next == ugly[ptr[j]] * primes[j]){
                            ptr[j]++;
                    }
                }
        }
        return ugly[n-1];
    }
};