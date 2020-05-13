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
  string removeKdigits(string num, int k) {
    const int n = num.size();
    if (n == k) return "0";
    stack<char> s;
    int i = 0;
    while (i < n) {
      while (k > 0 && !s.empty() && num[i] < s.top()) {
        s.pop();
        --k;
      }
      s.push(num[i]);
      ++i;
    }
    while (k > 0) {
      s.pop();
      --k;
    }
    string res = "";
    while (!s.empty()) {
      res += s.top();
      s.pop();
    }
    i = res.size() - 1;
    while (i > 0 && res[i] == '0') --i;
    res = res.substr(0, i + 1);
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
