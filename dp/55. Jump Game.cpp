class Solution {
public:
  bool canJump(vector<int> &nums) {
    vector<bool> dp(nums.size(), false);
    dp[nums.size() - 1] = true;
    for (int n = nums.size() - 2; n >= 0; n--) {
      for (int m = 1; m <= nums[n] && m + n < nums.size(); ++m) {
        if (dp[m + n]) {
          dp[n] = true;
          break;
        }
      }
    }
    return dp[0];
  }
};