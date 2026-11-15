class Solution {
public:
    int minimumChairs(string s) {
        int c = 0, p = 0;
        for (char& ch: s) {
            if (ch == 'E') {
                p += 1;
                if (c < p) {
                    c += 1;
                }
            } else {
                p -= 1;
            }
        }
        return c;
    }
};
