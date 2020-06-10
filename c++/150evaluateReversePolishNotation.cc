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
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (const string &t: tokens) {
      if (t.back() >= '0') {
        s.push(stoi(t));
      } else {
        int n2 = s.top(); s.pop();
        int n1 = s.top(); s.pop();
        switch (t[0]) {
          case '+': s.push(n1 + n2); break;
          case '-': s.push(n1 - n2); break;
          case '*': s.push(n1 * n2); break;
          case '/': s.push(n1 / n2); break;
          default: continue;
        }
      }
    }
    return s.top();
  }
};

int main() {
  Solution s;
  
  return 0;
}
