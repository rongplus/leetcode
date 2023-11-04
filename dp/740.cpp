#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>


using namespace std;
class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    // sort(nums.begin(), nums.end());
    map<int, int> num_pair;
    set<int> unique_nums;
    for (auto &v : nums) {
      num_pair[v]++;
      unique_nums.insert(v);
    }
    stack<int> ordered_nums;
    for (auto &v : unique_nums) {
      ordered_nums.push(v);
    }

    vector<int> dp(num_pair.size(), 0);
    int r1 = 0;
    int r2 = 0;
    int pre = -1;
    for (auto& it: num_pair)
    {
        int tmp = r2;
        r1 += it.first *  it.second;
        if (pre==it.first-1)
        {
            r2 = max(r1,tmp);
        }
        else{
            r2 += it.first *  it.second;
        }
      r1 = tmp;
    }

    return r2;

       int total = 0;
   
    if (ordered_nums.size()>0)
    {
      int v = ordered_nums.top();
      ordered_nums.pop();
      sum(v, ordered_nums,total);

    }

    return total;
  }

  int sum(int value,stack<int>& ordered_nums, int &total )
  {

  }
};

int main() { return 0; }