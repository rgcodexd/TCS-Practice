#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 0;
        
        // Helper function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the length of the valid palindrome found
            return right - left - 1;
        };
        
        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindromes (e.g., "aba" centered at 'b')
            int len1 = expandAroundCenter(i, i);
            
            // Even length palindromes (e.g., "abba" centered between 'b' and 'b')
            int len2 = expandAroundCenter(i, i + 1);
            
            int len = std::max(len1, len2);
            
            if (len > maxLength) {
                maxLength = len;
                // Calculate starting index of the new longest palindrome
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};