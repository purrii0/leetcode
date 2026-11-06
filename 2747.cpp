// naive solution - got me TLE
class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>> &logs, int x,
                           vector<int> &queries) {
    vector<int> arr(queries.size());
    int i = 0;
    for (int &query : queries) {
      int down = query - x, up = query;
      unordered_set<int> mp;
      for (vector<int> &log : logs) {
        if (log[1] >= down && log[1] <= up) {
          mp.insert(log[0]);
        }
      }
      arr[i] = n - mp.size();
      i += 1;
    }
    return arr;
  }
};
// optimized - got tle
class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>> &logs, int x,
                           vector<int> &queries) {
    vector<int> arr(queries.size());
    int i = 0;
    unordered_map<int, vector<int>> mp;
    for (vector<int> &log : logs) {
      mp[log[1]].push_back(log[0]);
    }
    for (int &query : queries) {
      int down = query - x, up = query;
      unordered_set<int> st;
      for (int i = down; i <= up; i++) {
        if (mp.count(i)) {
          vector<int> arr = mp[i];
          for (int &a : arr)
            st.insert(a);
        }
      }
      arr[i] = n - st.size();
      i += 1;
    }
    return arr;
  }
};
// more optimized - copied from editorial - can't understand it rn (will work on
// it)
class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>> &logs, int x,
                           vector<int> &queries) {
    sort(logs.begin(), logs.end(),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });

    vector<int> ids(queries.size());
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(),
         [&](int i, int j) { return queries[i] < queries[j]; });

    vector<int> ans(queries.size()), cnt(n + 1);
    int left = 0, right = 0, active = 0;
    for (int i : ids) {
      int q = queries[i];
      while (right < logs.size() && logs[right][1] <= q) {
        int id = logs[right++][0];
        if (cnt[id]++ == 0) {
          ++active;
        }
      }
      while (left < right && logs[left][1] < q - x) {
        int id = logs[left++][0];
        if (--cnt[id] == 0) {
          --active;
        }
      }
      ans[i] = n - active;
    }
    return ans;
  }
};
