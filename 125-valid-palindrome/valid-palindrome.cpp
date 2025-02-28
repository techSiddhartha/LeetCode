#include <string>
#include <cctype> 

class Solution {
public:
    bool isPalindrome(string s) {
        string normalized_str;
    
        for (char c : s) {
            if (isalnum(c)) {
                normalized_str += tolower(c);
            }
        }
        

        string reversed_str = string(normalized_str.rbegin(), normalized_str.rend());
        return normalized_str == reversed_str;
    }
};