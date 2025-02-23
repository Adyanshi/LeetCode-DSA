// the string will be palindrome if it is equal to its reverse
// the string contains only alphabets and digits
// the string is case-insensitive



// Time Complexity: O(n)
// Space Complexity: O(1)

#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        bool isAlphaNum(char c) {
            if ((tolower(c) >= 'a' && tolower(c) <= 'z') || (c >= '0' && c <= '9')){ return true;}
            return false;
        }
            bool isPalindrome(string s) {
                int st = 0, end = s.size() - 1;
                while (st < end) {
                    if (!isAlphaNum(s[st])) {
                        st++;
                        continue;
                    }
                    if (!isAlphaNum(s[end])) {
                        end--;
                        continue;
                    }
                    if (tolower(s[st]) != tolower(s[end]))
                        return false;
                    st++;
                    end--;
                }
                return true;
            }
    };