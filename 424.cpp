class Solution {
public:
  int characterReplacement(string s, int k) {
    int freq[128] = {0};
    int maxFreq = 0, maxLen = 0, l = 0, r = 0;

    while (r < s.size()) {
      char ch = s[r];
      freq[ch] += 1;

      maxFreq = max(maxFreq, freq[ch]);

      if ((r - l + 1) - maxFreq > k) {
        freq[s[l]]--;
        l++;
      }

      maxLen = max(maxLen, r - l + 1);
      r++;
    }
    return maxLen;
  }
};
