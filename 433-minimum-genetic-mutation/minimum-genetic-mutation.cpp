class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        unordered_map<string, int> mpp;
        for(auto &it : bank){
            mpp[it] = 1;
        }
        queue<pair<string, int>>q;
        q.push({startGene, 0});
        int ans = INT_MAX;
        char c[] = {'A', 'C', 'G', 'T'};
        while(!q.empty()){
            auto [temp, t] = q.front();
            q.pop();
            if(temp == endGene) {
                ans = t;
                break;
            }
            for(int i = 0; i<temp.size();i++){
                for(int j =0; j<4; j++){
                    string l = temp;
                    if(l[i] != c[j]) l[i]= c[j];
                    if(mpp.find(l) != mpp.end()){
                        mpp.erase(l);
                        q.push({l, t+1});
                    }
                }
            }
        }
        if(ans == INT_MAX ) return -1;
        return ans;
        
    }
};