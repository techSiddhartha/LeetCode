#include <string>
#include <cctype> 

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string normalized_str;
    
        for (char c : s) {
            if (std::isalnum(c)) {
                normalized_str += std::tolower(c);
            }
        }
        

        std::string reversed_str = std::string(normalized_str.rbegin(), normalized_str.rend());
        return normalized_str == reversed_str;
    }
};