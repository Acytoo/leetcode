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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    int n2 = B.size();
    int res = 1;
    string s = A;
    while (s.size() < n2) {
      s += A;
      ++res;
    }
    if (s.find(B) != string::npos) return res;
    s += A;
    return s.find(B) == string::npos? -1: res+1;
  }
};

int main() {
  Solution s;
  cout << s.repeatedStringMatch("abcd", "abcdabcdabcd") << endl;
  return 0;
}
