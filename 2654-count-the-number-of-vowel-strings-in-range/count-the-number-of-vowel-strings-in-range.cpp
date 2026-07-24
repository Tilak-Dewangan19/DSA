class Solution {
public:
bool isvowel(char c){
    return c =='a' || c=='e' || c=='i' || c== 'o' || c=='u';
}
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i = left; i<= right; i++){
       auto& word = words[i];
        
            int n = word.size();
            if(isvowel(word[0]) && isvowel(word[n-1])) cnt++;
        
        }
        return cnt;
    }
};