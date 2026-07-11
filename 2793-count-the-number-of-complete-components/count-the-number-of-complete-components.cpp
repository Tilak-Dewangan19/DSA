class Solution {
public:
void dfs(int i, unordered_map<int, vector<int>>&adj, vector<int>&vis, vector<int>& comp){
    comp.push_back(i);
    vis[i] = 1;

    for(auto &j : adj[i]){
        if(!vis[j]){
            vis[j]=1;
            dfs(j, adj, vis, comp);
        }
    }

}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;

        for(auto &c : edges){
            int v = c[0];
            int u = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int>vis(n, 0);
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){ 
                vector<int>comp;
                dfs(i, adj, vis, comp);
                bool flag = 1;
                int size = comp.size();
                for(auto &j : comp){
                    if(adj[j].size() != size-1){
                        flag = 0;
                        break;
                    }
                }
                if(flag) cnt++;

            }
        }
        return cnt;
        
    }
};