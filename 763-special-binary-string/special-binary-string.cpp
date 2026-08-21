class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>parts;

        int count = 0;
        int start = 0;

        for(int i =0; i< s.size(); i++){
            if(s[i] == '1'){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                string inside = s.substr(start+1, i- (start+1));
                inside = makeLargestSpecial(inside);
                parts.push_back("1"+ inside+ "0");
                start = i+1;
            }
        }
        sort(parts.rbegin(), parts.rend());
        string ans="";
        for(auto& part : parts){
                ans+=part;
        }

        return ans;
    }
};