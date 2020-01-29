#include <iostream>
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
#include <set>
#include <functional>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    res.reserve(right-left);
    while (left <= right) {
      if (helper(left))
        res.emplace_back(left);
      ++left;
    }
    return res;
  }
 private:
  bool helper(int n) {
    int num = n;
    while (n > 0) {
      int newN = n / 10;
      int dig = n - (newN << 3) - (newN << 1);
      if (dig == 0 || num % dig != 0)
        return false;
      n = newN;
    }
    return true;
  }
};


class Solution1 {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    res.reserve(right-left);
    while (left <= right) {
      if (helper(left))
        res.emplace_back(left);
      ++left;
    }
    return res;
  }
 private:
  bool helper(int n) {
    int num = n;
    while (n > 0) {
      int dig = n % 10;
      if (dig == 0 || num % dig != 0)
        return false;
      n /= 10;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
