class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s;
		for (int &x : nums) {
			s.insert(x);
		}
		int maxCount = 0;
		for (int x : s) {
			if (!s.count(x - 1)) {
                int count = 0;
                int curr = x;
			    while (s.count(curr++)) {
				    count++;
			    }
			    maxCount = max(count, maxCount);
            }
		}
		return maxCount;
	}
};


