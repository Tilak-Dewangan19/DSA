class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
       vector<int>time;
       for(auto& c : timePoints){
        int hour = stoi(c.substr(0, 2));
        int minute = stoi(c.substr(3, 2));

        time.push_back(hour* 60+ minute);
       }
        sort(time.begin(), time.end());
        int ans = INT_MAX;

        for(int i = 1; i< timePoints.size(); i++){
            ans= min(ans, time[i]- time[i-1]);


        }
        ans = min(ans, 1440-time.back()+ time[0]);
       
        return ans;
        
    }
};