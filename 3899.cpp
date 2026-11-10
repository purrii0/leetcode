class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c) return {};
        double a2 = a * a, b2 = b * b, c2 = c * c;
        double angleA = std::acos((b2 + c2 - a2) / (2.0 * b * c));
        double angleB = std::acos((a2 + c2 - b2) / (2.0 * a * c));
        double angleC = std::acos((b2 + a2 - c2) / (2.0 * b * a));
        double factor = 180.0 / acos(-1.0);
        vector<double> ans = {angleA * factor, angleB * factor, angleC * factor};
        sort(ans.begin(), ans.end());
        return ans;
    }
};
