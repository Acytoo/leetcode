#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    const int n = num.size();
    vector<string> res;
    function<void(int, long, long, string)> helper
        = [&] (int idx, long cur_num, long pre_num, string cur_expression) {
          if (idx == n) {
            if (cur_num == target) res.push_back(cur_expression);
            return;
          }
          for (int l = 1, stop = n - idx; l <= stop; ++l) {
            string new_expression = num.substr(idx, l);
            if (new_expression[0] == '0' && new_expression.size() > 1) break;
            long new_num = stol(new_expression);
            helper(idx + l, cur_num + new_num, new_num, cur_expression + '+' + new_expression);
            helper(idx + l, cur_num - new_num, -new_num, cur_expression + '-' + new_expression);
            helper(idx + l, cur_num - pre_num + pre_num * new_num, pre_num * new_num, cur_expression + '*' + new_expression);
          }
    };
    for (int l = 1; l <= n; ++l) {
      string start_expression = num.substr(0, l);
      if (start_expression[0] == '0' && start_expression.size() > 1) break;
      long start_num = stol(start_expression);
      helper(l, start_num, start_num, start_expression);
    }
    return res;
  }
};

// "1 + 0 * 5" = 1, not 5
class Solution_WA {
 public:
  vector<string> addOperators(string num, int target) {
    // int cur = 0, idx = 0;
    const int n = num.size();
    vector<string> res;
    function<void(int, long, string)> helper = [&] (int idx, long cur_num, string cur_expression) {
      if (idx == n) {
        if (target == cur_num) res.push_back(cur_expression);
        return;
      }
      for (int l = 1, stop = n - idx; l <= stop; ++l) {
        string new_expression = num.substr(idx, l);
        long new_num = stol(new_expression);
        helper(idx + l, cur_num + new_num, cur_expression + '+' + new_expression);
        helper(idx + l, cur_num - new_num, cur_expression + '-' + new_expression);
        helper(idx + l, cur_num * new_num, cur_expression + '*' + new_expression);
      }
    };
    for (int l = 1; l <= n; ++l) {
      string start_expression = num.substr(0, l);
      long start_num = stol(start_expression);
      helper(l, start_num, start_expression);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
