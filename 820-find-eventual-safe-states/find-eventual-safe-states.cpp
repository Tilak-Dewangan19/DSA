class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          vector<vector<int>> revAdj(graph.size());
        vector<int> outdegree(graph.size(), 0);
for(int i = 0; i< graph.size(); i++){
    outdegree[i] = graph[i].size();

        for(auto it : graph[i]){
            revAdj[it].push_back(i);
        }
        }
         queue<int> q;

        for(int i=0;i<graph.size();i++){
            if(outdegree[i]==0)
                q.push(i);
        }
    vector<int> ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:revAdj[node]){
                outdegree[it]--;
                if(outdegree[it]==0)
                    q.push(it);
            }
        }
       sort(ans.begin(), ans.end());
            return ans;
        
       
        
        
    }
};