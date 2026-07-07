class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(auto &c : s){
            c = tolower(c);
           
                ans+=c;
            }
             return ans;
        }
       
    
};