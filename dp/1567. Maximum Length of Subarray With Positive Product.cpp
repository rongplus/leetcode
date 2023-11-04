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
  int maxProduct(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    long long sum = 1;
    long long max_value = INT_MIN;

    vector<int> sub;
    for (auto &v : nums) {
      if (v != 0) {
        sub.push_back(v);
        sum *= v;
      } else {
        if (sub.size() != 0) {
          if (sum > 0) {
            max_value = max(max_value, sum);
          } else
            max_value = max(max_value, sub_fun(sub, sum));
        }

        { max_value = max(max_value, (long long)0); }
        sum = 1;
        vector<int> n_sub;
        swap(sub, n_sub);
      }
    }
    if (sub.size() > 0) {
      if (sum < 0)
        max_value = max(max_value, sub_fun(sub, sum));
      else
        max_value = max(max_value, sum);
    }

    return max_value;
  }

  long long sub_fun(vector<int> &nums, long long &sum) {
    // first/last  negotive
    if (nums.size() == 1)
      return sum;
    cout << "input = " << sum << endl;
    auto it_f = find_if(nums.begin(), nums.end(), [](int v) { return v < 0; });
    auto it_e =
        find_if(nums.rbegin(), nums.rend(), [](int v) { return v < 0; });
    cout << "pos = " << it_f - nums.begin() << endl;
    cout << "last pos = " << it_e - nums.rbegin() << endl;

    /* if (it_f - nums.begin() == nums.size() -1 - (it_e - nums.rbegin()) )
         return 0;*/

    long long tmp = sum;
    // if (nums.size() - (it_f - nums.begin() + 1) != 1)
    {
      for (int n = 0; n <= it_f - nums.begin(); ++n) {
        tmp /= nums[n];
      }
    }

    // if (nums.size() - (it_e - nums.rbegin()) != 1)
    {
      for (int n = 0; n <= it_e - nums.rbegin(); ++n) {
        sum /= nums[nums.size() - n - 1];
      }
    }

    cout << sum << "- " << tmp << endl;

    return max(sum, tmp);
  }
};

int main() {
  Solution s;
  vector<int> v = {1,  2, 3, -1, 5, 9, -4, 5, 2, -4, 8,
                   -4, 5, 5, -4, 0, 1, 2,  3, 4, 5,  6};
  vector<int> v2 = {2, 3, -2, 4};
  vector<int> v3 = {3, -1, 4};
  cout << "max = " << s.maxProduct(v3) << endl;
  return 0;
}