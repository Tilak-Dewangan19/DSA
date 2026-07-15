class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>temp(n+1);
        temp[0] = 0;
        for(int i = 1; i<=n; i++){
            temp[i] = (temp[i-1]+ gain[i-1]);
        }
        return *max_element(temp.begin(), temp.end());
    }
};