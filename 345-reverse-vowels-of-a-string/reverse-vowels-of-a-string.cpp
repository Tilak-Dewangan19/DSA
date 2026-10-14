#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvowel(char c){
        return c == 'a'|| c== 'e' || c == 'i' || c == 'o' || c == 'u'|| c == 'A'|| c== 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        // Write your code here
        int l = 0;
        int r = s.size()-1;

        while(l < r){
            while(l < r && !isvowel(s[l])){
                l++;
            }
            while( l< r && !isvowel(s[r])){
                r--;
            }
            if(l < r) {
                swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};
