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
class Solution {  // 12 ms
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> table (numRows);
    --numRows;  // convert size to idx
    int cur_row = 0;
    bool down = true;
    for (const char c: s) {
      table[cur_row].push_back(c);
      if (down) {
        if (cur_row < numRows) {
          ++cur_row;
          continue;
        }
        down = false;
        --cur_row;
      } else {
        if (cur_row > 0) {
          --cur_row;
          continue;
        }
        down = true;
        cur_row = 1;
      }
    }
    string res;
    for (string &row: table) res += row;
    return res;
  }
};

class Solution_basic {  // 20 ms
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    const int n = s.size();
    vector<string> table (numRows);
    --numRows;  // convert size to idx
    int cur_row = 0;
    bool down = true;
    for (int i = 0; i < n; ++i) {
      table[cur_row].push_back(s[i]);
      if (down && cur_row < numRows) {
        ++cur_row;
      } else if (down && cur_row == numRows) {
        down = false;
        --cur_row;
      } else if (cur_row == 0) {
        down = true;
        cur_row = 1;
      } else {
        --cur_row;
      }
    }
    string res;
    for (string &row: table) res += row;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
