#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        int compress(vector<char>& chars) {
            int n = chars.size();
            int idx = 0;
            for(int i = 0; i<n ; i++){
                char ch = chars[i];
                int count = 0;
                while(i<n && chars[i] == ch){
                    count++; i++;
                }
                if(count == 1){
                    chars[idx++] = ch;
                }
                else{
                    chars[idx++] = ch; 
                    string str = to_string(count); // to add count as character 
                    for(char dig : str){
                        chars[idx++] = dig;
                    }
                }
                i--; // to shift i backwards
            }
            chars.resize(idx);
            return idx;
        }
    };