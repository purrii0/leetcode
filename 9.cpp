class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long reverse = 0, xcopy = x;

        while (xcopy) {
            reverse = (reverse * 10) + (xcopy % 10);
            xcopy /= 10;
        }
        return reverse == x;
    }
};
