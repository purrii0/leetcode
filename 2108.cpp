class Solution {
public:
  string firstPalindrome(vector<string> &words) {
    for (string &s : words) {
      if (isPalindrome(s)) {
        return s;
      }
    }
    return "";
  }
  bool isPalindrome(string &s) {
    int st = 0, end = s.size() - 1;
    while (st < end) {
      if (s[st] != s[end])
        return false;
      st++;
      end--;
    }
    return true;
  }
};
