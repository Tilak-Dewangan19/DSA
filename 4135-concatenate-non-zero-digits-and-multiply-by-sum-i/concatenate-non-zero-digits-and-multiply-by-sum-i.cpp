class Solution {
public:
    long long sumAndMultiply(int n) {
        string ans="";
        int sum = 0;
        string s = to_string(n);
        for(auto &c : s){
            if(c != '0'){
                ans+=c;
                sum = sum+(c- '0');

            }
        }
        if(ans.empty()) return 0;
        long long x = stoll(ans);
        return x * sum;

        
    }
};