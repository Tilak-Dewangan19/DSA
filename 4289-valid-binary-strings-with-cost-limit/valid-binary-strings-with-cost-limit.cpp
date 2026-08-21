class Solution {
public:
    void solve(int n, string s, vector<string>&ans,int k){
        if(s.size() == n){
           
            int cost = 0;
            for(int i =0; i< n; i++){
                if(s[i] == '1')
                cost+=i;
            
            }
            if(cost <=k){
                ans.push_back(s);
            }
            return;
        }
        solve(n, s+'0', ans,k);
        if(s.empty() || s.back()!= '1'){
            solve(n, s+'1', ans, k);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
     vector<string>ans;
     solve(n,"", ans, k);

        return ans;
    }
};