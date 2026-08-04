class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>vis(n, false);
        queue<int>q;
        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(arr[i] == 0){
                return true;
            }

            int right = i + arr[i];
            int left = i-arr[i];

            if(right < n && !vis[right]){
                q.push(right);
                vis[right] = true;
            }
            if(left >=0 && !vis[left]){
                q.push(left);
                vis[left] = true;
            }
        }
        
        return false;
        
    }
};