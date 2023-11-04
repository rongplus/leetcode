class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];

    vector<int> dp(nums.size(), 0);
    for (int n = nums.size() - 1; n >= 0; --n) {
      dp[n] = robFun(nums, n, dp);
    }
    return max(dp[0], dp[1]);
  }

  int robFun(vector<int> &nums, int n, vector<int> &dp) {
    if (n == nums.size() - 1)
      return nums[n];
    else if (n == nums.size() - 2) {
      return max(nums[n], nums[n + 1]);
    }
    return max(dp[n + 2] + nums[n], dp[n + 1]);
  }

  int rob2(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];

    vector<int> dp(nums.size(), 0);
    size_t sz = nums.size();
    dp[sz - 1] = nums[sz - 1];
    dp[sz - 2] = max(nums[sz - 1], nums[sz - 2]);

    for (int n = nums.size() - 3; n >= 0; --n) {
      dp[n] = max(dp[n + 2] + nums[n], dp[n + 1]);
    }
    return max(dp[0], dp[1]);
  }
};

class SolutionCircle {
public:
  int rob(vector<int> &nums) {
    size_t sz = nums.size();
    if (sz == 0)
      return 0;
    if (sz == 1)
      return nums[0];
    if (sz == 2) {
      return max(nums[0], nums[1]);
    }
    if (sz == 3) {
      return max(max(nums[0], nums[1]), nums[2]);
    }

    nums.push_back(nums[0]);
    nums.push_back(nums[1]);
    sz += 2;

    vector<int> dp(sz, 0);

    dp[sz - 1] = nums[sz - 1];
    dp[sz - 2] = nums[sz - 2];
    dp[sz - 3] = nums[sz - 3];

    for (int n = nums.size() - 4; n >= 0; --n) {
      dp[n] = max(dp[n + 2] + nums[n], dp[n + 1]);
    }
    return dp[2];
  }
};