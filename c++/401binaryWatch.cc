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
  vector<string> readBinaryWatch(int num) {
    if (num == 0) return {"0:00"};
    auto possible = [] (const int num, const int r) {
                      vector<int> res;
                      for (int i = 0; i < r; ++i)
                        if (__builtin_popcount(i) == num)
                          res.emplace_back(i);
                      return res;
                    };
    char cur_time[6];
    vector<string> res;
    for (int i = 0; i <= num; ++i)
      for (const int h: possible(i, 12))
        for (const int m: possible(num - i, 60)) {
          sprintf(cur_time, "%d:%02d\0", h, m);
          res.emplace_back(cur_time);
        }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
