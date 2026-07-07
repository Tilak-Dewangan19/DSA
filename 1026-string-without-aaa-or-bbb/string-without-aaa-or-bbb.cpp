class Solution {
public:
    string strWithout3a3b(int a, int b) {
      string ans ="";
      while(a > 0 || b >0){
        int n =ans.size();
        if(n >= 2 && ans[n-1] == ans[n-2]){
            if(ans[n-1] == 'a'){
                ans+='b';
                b--;
            }
            else{
                ans+='a';
                a--;
            }

        }
        else{
            if(a >= b && a > 0){
                ans+='a';
                a--;

            }
            else if(b>= a && b > 0){
                ans+='b';
                b--;
            }
           
        }
      }
        return ans;
        
    }
};