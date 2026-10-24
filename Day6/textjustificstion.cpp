
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int len = 0;

            // Pack as many words as possible
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line or line with only one word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += ' ';
                    }
                }

                while (line.size() < maxWidth) {
                    line += ' ';
                }
            } 
            else {
                int totalSpaces = maxWidth - len;
                int spaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];

                    int count = spaces;
                    if (k - i < extraSpaces) {
                        count++;
                    }

                    line += string(count, ' ');
                }

                line += words[j - 1];
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
