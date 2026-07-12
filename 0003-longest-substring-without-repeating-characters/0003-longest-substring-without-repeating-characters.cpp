#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            
            // If character already exists in current window
            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            }

            // Store/update latest index of character
            mp[s[right]] = right;

            // Calculate window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};