class Solution {
public:
 bool isvowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    
 }
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;

        for(int i = 0; i < k; i++){
            if(isvowel(s[i])){
                cnt++;
            }
        }
        int ans = cnt;

        for(int i = k; i < n; i++){
            if(isvowel(s[i])){
                cnt++;
            }
            if(isvowel(s[i-k])){
                cnt--;
            }
            ans = max(cnt,ans);
        }
       return ans;
    }
};