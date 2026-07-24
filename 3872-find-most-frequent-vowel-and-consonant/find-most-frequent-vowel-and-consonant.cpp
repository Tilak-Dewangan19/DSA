class Solution {
public:
    bool isvowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
       vector<int>freq(26, 0);
       for(int i =0; i<s.size(); i++){
        freq[s[i]-'a']++;
       }
       int vowel = 0;
       int cons = 0;
       for(int i =0; i<26; i++){
        char ch = i + 'a';
        if(isvowel(ch)){
            vowel = max(vowel, freq[i]);
        }
        else{
            cons = max(cons, freq[i]);
        }
       

       }
       return vowel+ cons;
        
    }
};