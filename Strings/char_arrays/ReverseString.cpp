#include<iostream>
#include<string>
#include <vector>
using namespace std;

// Reverse a string
// Given a character array s, reverse the order of its elements.

//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
    public:
        void reverseString(vector<char>& s) {
            int st=0,end=s.size()-1;
            while(st<end){
                swap(s[st++],s[end--]);
            }
        }
    };