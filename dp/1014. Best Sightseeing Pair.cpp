class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int sz = values.size() - 1;
    int max_r = values[sz] - sz;
    int result = INT_MIN;
    for (int n = sz - 1; n >= 0; n--) {

      result = max(max_r + values[n] + n, result);
      max_r = max(max_r, values[n] - n);
    }
    return result;
  }

  int getValue(vector<int> &values, int i, int j) {
    return values[i] + values[j] + i - j;
  }
};