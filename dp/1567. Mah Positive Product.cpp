// Leetcode.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
  int getMaxLen(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0] <= 0 ? 0 : 1;
    }
    int sum = 1;
    int max_len = 0;

    int l = -1;
    int r = -1;
    int cur = 0;
    for (auto v : nums) {
      if (v == 0) {
        if (sum > 0) {
          max_len = max(max_len, cur);
        } else {
          max_len = max(max_len, cur - 1 - 1);
          max_len = max(max_len, r);
        }

        sum = 1;
        l = -1;
        r = -1;
        cur = 0;
      } else {
        sum *= v > 0 ? 1 : -1;

        if (v < 0 && l == -1) {
          l = cur;
        }
        if (v < 0) {
          r = cur;
        }
        ++cur;
      }
    }

    if (sum > 0) {
      max_len = max(max_len, cur);
    } else {
      max_len = max(max_len, cur - l - 1);
      cout << "max" << max_len << " cur=" << cur << " l = " << l << endl;
      max_len = max(max_len, r);
      cout << "heer\n";
    }
    return max_len;
  }
};

int main() {
  Solution s;
  vector<int> v = {1,  2, 3, -1, 5, 9, -4, 5, 2, -4, 8,
                   -4, 5, 5, -4, 0, 1, 2,  3, 4, 5,  6};
  vector<int> v2 = {-1, 2};
  vector<int> v3 = {-4, 12,  -35, 0,  5,  -39, 3,  -25, -19, -12,
                    23, -33, 13,  21, 12, -25, 15, 9,   38,  -38};
  cout << "max = " << s.getMaxLen(v2) << endl;
  return 0;
}