class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int s1 =0, s2 = 0, a = 0, b = 0;
        for(int i = 0; i< n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    a++;
                }
                else{
                    b++;
                }
            }
            else{
                if(i<n/2){
                    s1+=num[i] - '0';
                }
                else{
                    s2+=num[i] - '0';
                }
            }
        }
            if((a + b) % 2 == 1){
                return true;
            }

        return (2*(s1-s2) + 9*(a-b) != 0);
        
    }
};