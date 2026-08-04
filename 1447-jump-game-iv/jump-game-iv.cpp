class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(arr.size() == 1) return 0;
        unordered_map<int, vector<int>>mpp;
        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<bool>vis(arr.size(), false);
        q.push(0);
        vis[0] = true;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int idx = q.front();
                q.pop();

                if(idx == n-1){
                    return steps;
                }
                if(idx-1 >=0 && !vis[idx-1]){
                    vis[idx-1] =true;
                    q.push(idx-1);
                }
                if(idx+1 <arr.size() && !vis[idx+1]){
                    vis[idx+1] = true;
                    q.push(idx+1);
                }
                 for (int id : mpp[arr[idx]]) {
                    if (!vis[id]) {
                        vis[id] = true;
                        q.push(id);
                    }
                }

                // Clear to avoid processing the same value again
                mpp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
            }

        


   
        
    
};