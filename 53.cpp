// kadane algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS = nums[0], currS;
        for (int &x : nums) {
            currS += x;
            currS = max(currS, x);
            maxS = max(maxS, currS);
        }  
        return maxS;
    }
};
