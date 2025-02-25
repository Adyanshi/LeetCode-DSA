#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        string reverseWords(string s) { //reverse whole string and then reverse each word in it.
            int n = s.length();
            string ans = "";
            reverse(s.begin(), s.end());
            // for each word in a string
            for(int i = 0 ; i < n; i++){
                string word = "";
                while(i < n && s[i] != ' '){
                    word += s[i];
                    i++;
                }
                reverse(word.begin(), word.end()); //reverse words each
                if(word.length() > 0){
                    ans += " " + word;
                }
            }
            return ans.substr(1);//to remove spaces from the start
        }
};