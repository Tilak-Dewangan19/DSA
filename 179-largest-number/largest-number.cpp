class Solution {
public:
    static bool cmp(string &a, string &b){
        return a+b > b+a;
     }
    string largestNumber(vector<int>& nums) {

        vector<string>ans;
        for(auto &c : nums){
            ans.push_back(to_string(c));
        }
        sort(ans.begin(), ans.end(), cmp);
        if(ans[0] == "0"){
            return "0";
        }
        string temp="";
        for(auto &b : ans){
            temp+=b;
        }
        return temp;
    }
};