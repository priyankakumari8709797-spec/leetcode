#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector to store the last seen index of each character (ASCII 128)
        vector<int> lastIndex(128, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character was seen within the current window, move left
            if (lastIndex[currentChar] >= left) {
                left = lastIndex[currentChar] + 1;
            }
            
            // Update the last seen index of the character
            lastIndex[currentChar] = right;
            
            // Calculate max window size
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};