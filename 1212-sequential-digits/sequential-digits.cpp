class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s ="123456789";
      
        int minl = to_string(low).size();
        int maxl = to_string(high).size();

        for(int len = minl; len <= maxl; len++){
            for(int i = 0; i+ len <=9; i++){

                int num = stoi(s.substr(i, len));

                     if(num >= low && num <= high){
                        ans.push_back(num);
                     }
            }
        }
       
      return ans;
        
    }
};