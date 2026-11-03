class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::vector<int> mp(128, 0);
    int l = 0, r = 0;
    int maxS = 0;
    while (r < s.size()) {
      if (mp[s[r]] == 0) {
        mp[s[r]] = 1;
        maxS = max(maxS, r - l + 1);
        r++;
      } else {
        mp[s[l]] = 0;
        l++;
      }
    }

    return maxS;
  }
};
