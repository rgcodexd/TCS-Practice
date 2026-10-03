#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        if (s.length() < totalLen) return result;

        // Frequency map of all words in the input array
        std::unordered_map<std::string, int> wordMap;
        for (const std::string& word : words) {
            wordMap[word]++;
        }

        // Iterate over all possible starting offsets (0 to wordLen - 1)
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            std::unordered_map<std::string, int> seenMap;
            int count = 0; // Number of valid words in the current window

            while (right + wordLen <= s.length()) {
                std::string sub = s.substr(right, wordLen);
                right += wordLen;

                // Check if the word is part of words
                if (wordMap.find(sub) != wordMap.end()) {
                    seenMap[sub]++;
                    count++;

                    // If we have more occurrences of 'sub' than needed, shrink from the left
                    while (seenMap[sub] > wordMap[sub]) {
                        std::string leftWord = s.substr(left, wordLen);
                        seenMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If the window matches all words required
                    if (count == numWords) {
                        result.push_back(left);
                        // Shift left by one word to search for the next match
                        std::string leftWord = s.substr(left, wordLen);
                        seenMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    // Not a valid word, reset the window
                    seenMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};