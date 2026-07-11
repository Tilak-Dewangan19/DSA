class Solution {
public:
    bool isvowel(char c){
        return c == 'a'|| c == 'e'|| c == 'i'|| c == 'o' ||c == 'u' ||c == 'A'|| c == 'E'|| c == 'I'|| c == 'O' ||c == 'U';
    }
    string sortVowels(string s) {
        int n =s.size();
        vector<char>temp;
        for(auto &c : s){
            if(isvowel(c)){
                temp.push_back(c);
            }

        }
        sort(temp.begin(), temp.end());
        int j =0;
        for(int i =0; i<n; i++){
            if(isvowel(s[i])){
                s[i] = temp[j++];

            }
        }
        return s;
    }
};