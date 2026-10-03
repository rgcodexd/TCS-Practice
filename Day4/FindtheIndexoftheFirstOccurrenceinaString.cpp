#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // find() returns the index of the first occurrence, or std::string::npos if not found
        size_t pos = haystack.find(needle);
        
        if (pos != std::string::npos) {
            return static_cast<int>(pos);
        }
        return -1;
    }
};