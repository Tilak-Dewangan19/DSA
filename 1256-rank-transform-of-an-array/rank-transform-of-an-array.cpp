class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int>mpp;
        int rank = 1;
        for(auto &c : temp){
            if(mpp.find(c) == mpp.end()){
                mpp[c] = rank++;
            }
        }

            for(int i = 0; i< n; i++){
                arr[i] = mpp[arr[i]];
            }
           

        
        return arr;

    }
};