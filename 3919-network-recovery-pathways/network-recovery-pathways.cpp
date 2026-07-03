class Solution {
public:
    bool check(int mid,
               vector<vector<pair<int,int>>> &adj,
               vector<bool>& online,
               long long k,
               int n){

        const long long INF = 1e18;

        vector<int> indegree(n,0);

        for(int u=0;u<n;u++){
            for(auto &it:adj[u]){
                int v=it.first;
                int w=it.second;

                if(w>=mid &&
                  (v==n-1 || online[v]))
                    indegree[v]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        vector<long long> dist(n,INF);
        dist[0]=0;

        while(!q.empty()){

            int u=q.front();
            q.pop();

            for(auto &it:adj[u]){

                int v=it.first;
                int w=it.second;

                if(w<mid) continue;

                if(v!=n-1 && !online[v]) continue;

                if(dist[u]!=INF)
                    dist[v]=min(dist[v],dist[u]+w);

                indegree[v]--;

                if(indegree[v]==0)
                    q.push(v);
            }
        }

        return dist[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n=online.size();

        vector<vector<pair<int,int>>> adj(n);

        int mx=0;

        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            mx=max(mx,e[2]);
        }

        int low=0,high=mx;
        int ans=-1;

        while(low<=high){

            int mid=(low+high)/2;

            if(check(mid,adj,online,k,n)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }

        return ans;
    }
};