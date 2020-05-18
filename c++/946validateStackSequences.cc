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
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    const int n = pushed.size();
    stack<int> s;
    int i = 0;
    for (const int num: pushed) {
      s.push(num);
      while (!s.empty() && i < n && s.top() == popped[i]) {
        ++i;
        s.pop();
      }
    }
    return i == n;
  }
};

int main() {
  Solution s;
  
  return 0;
}
