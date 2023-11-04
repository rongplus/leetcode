#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    long long sum = 1;
    long long max_value = INT_MIN;

    vector<int> sub;
    for (auto &v : nums) {
      if (v != 0) {
        sub.push_back(v);
        sum *= v;
      } else {
        if (sum > 0) {
          max_value = max(max_value, sum);
        } else
          max_value = max(max_value, sub_fun(sub, sum));
        sum = 1;
        vector<int> n_sub;
        swap(sub, n_sub);
      }
    }
    return max_value;
  }

  long long sub_fun(vector<int> &nums, long long &sum) {
    // first/last  negotive
    cout << "input = " << sum << endl;
    auto it_f = find_if(nums.begin(), nums.end(), [](int v) { return v < 0; });
    auto it_e =
        find_if(nums.rbegin(), nums.rend(), [](int v) { return v < 0; });
    cout << "pos = " << it_f - nums.begin() << endl;
    cout << "last pos = " << it_e - nums.rbegin() << endl;

    long long tmp = sum;

    for (int n = 0; n <= it_f - nums.begin(); ++n) {
      tmp /= nums[n];
    }
    for (int n = 0; n <= it_e - nums.rbegin(); ++n) {
      sum /= nums[nums.size() - n - 1];
    }

    return max(sum, tmp);
  }
};

int main() {
  Solution s;
  vector<int> v = {1,  2, 3,  -1, 5,  6, -2, 5,  6, 9, -3, 9, 4, 5, 2,
                   -4, 8, -2, 3,  -4, 5, 5,  -4, 0, 1, 2,  3, 4, 5, 6};
  vector<int> v2 = {2, 3, -2, 4};
  cout << "max = " << s.maxProduct(v2) << endl;
  return 0;
}