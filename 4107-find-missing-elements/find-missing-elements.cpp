class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        
int n = nums.size();

unordered_set<int>st;
for(int x : nums){
st.insert(x);
}
vector<int>ans;
        for(int i = mini; i<=maxi; i++){
            if(st.find(i)== st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};