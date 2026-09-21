#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge cases where zigzag pattern is identical to input
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            // Reverse direction when hitting the top or bottom boundary
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};