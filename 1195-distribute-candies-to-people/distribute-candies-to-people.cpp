class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0;
 int give = 1;
        while(candies > 0){
           
            ans[i % num_people] += min(give, candies);
            candies-=min(give, candies);
            give++;
            i++;
        }
        return ans;
    }
};