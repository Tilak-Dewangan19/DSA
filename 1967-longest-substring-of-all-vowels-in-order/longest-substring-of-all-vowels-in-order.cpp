class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int len = 1;
        int cnt = 1;
        int ans = 0;

        for(int i = 1; i<n; i++){
            if(word[i] >=  word[i-1]){
                len++;
                if(word[i] > word[i-1]){
                    cnt++;
                }
            }
            else{
                len = 1;
                cnt = 1;

            }
             if(cnt == 5){
            ans = max(ans, len);
        }
        }
       
    return ans;
    }
};