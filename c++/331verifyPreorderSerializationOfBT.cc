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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    int pos = 0;
    return isValid(preorder, pos) && pos == preorder.size();
  }
 private:
  bool isValid (const string &s, int &pos) {
    if (pos >= s.size()) return false;
    if (isdigit(s[pos])) {
      while (isdigit(s[pos])) ++pos;  // "123,#,#"
      return isValid(s, ++pos) && isValid(s, ++pos);
    }
    return s[pos++] == '#';
  }
};

int main() {
  Solution s;
  
  return 0;
}
