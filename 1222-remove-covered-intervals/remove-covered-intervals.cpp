class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int x = intervals[0][0];
        int y = intervals[0][1];
        int count = 1;

        for(int i =1; i<n; i++){
            if(intervals[i][0] > x && intervals[i][1] <= y)continue;
            else if(intervals[i][0] == x) y = max(y, intervals[i][1]);
            else{
                x = intervals[i][0];
                y = intervals[i][1];
                count++;

            }
        }
    

    return count;
        
    }
};