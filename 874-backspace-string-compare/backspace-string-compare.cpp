#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Write your code here
        string a = "";
        string b ="";
        for(auto& c : s){
            if(c != '#'){
                a+=c;
            }
            else if(!a.empty()){
                a.pop_back();
            }
        }
          for(auto& c : t){
            if(c != '#'){
                b+=c;
            }
            else if(!b.empty()){
                b.pop_back();
            }
        }
        if(a == b){
            return true;
        }
        return false;
    }
};
