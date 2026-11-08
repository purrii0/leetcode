// looked up editorial
class Solution {
public:
  int countServers(vector<vector<int>> &grid) {
    int count = 0;
    int m = grid.size(), n = grid[0].size();
    vector<int> rows(m), cols(n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rows[i] += grid[i][j];
        cols[j] += grid[i][j];
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] && rows[i] + cols[j] > 2) {
          count++;
        }
      }
    }
    return count;
  }
};
