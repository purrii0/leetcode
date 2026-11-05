class Solution {
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    int count = 0;
    bool isTrue = false;
    for (int &n : arr1) {
      isTrue = false;
      for (int &x : arr2) {
        isTrue = isTrue || (abs(n - x) <= d);
        if (isTrue)
          break;
      }
      if (!isTrue)
        count++;
    }
    return count;
  }
};
