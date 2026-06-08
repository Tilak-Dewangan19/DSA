class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        vector<int> a = intervals[0];
        vector<vector<int>> ans;

        for(int i = 1; i< n; i++){
            vector<int>b = intervals[i];
            if( b[0] <= a[1]){
                a[1] = max(a[1], b[1]);
            }
            else{
                    
                    ans.push_back(a);
                    a = b;
            }
        }
            ans.push_back(a);
        
        return ans;
    }
};