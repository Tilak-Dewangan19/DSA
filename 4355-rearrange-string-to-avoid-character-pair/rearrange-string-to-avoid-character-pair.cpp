class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char, int>freq;
        for(auto& c : s){
            freq[c]++;
        }
        string ans ="";
        while(freq[y] > 0){
            ans+=y;
            freq[y]--;

        }
        while(freq[x]>0){
            ans+=x;
            freq[x]--;
        }
        for(auto&[c,count] : freq){
           while(count>0){
                ans+=c;
                count--;
            }

        }
        return ans;
    }
};