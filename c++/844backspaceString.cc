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
  bool backspaceCompare(string S, string T) {
    stack<char> stack_s, stack_t;
    for (char c: S)
      if (c != '#')
        stack_s.push(c);
      else if (!stack_s.empty())
        stack_s.pop();
    for (char c: T)
      if (c != '#')
        stack_t.push(c);
      else if (!stack_t.empty())
        stack_t.pop();

    if (stack_s.size() != stack_t.size())
      return false;

    while (!stack_s.empty()) {
      if (stack_s.top() != stack_t.top())
        return false;
      stack_s.pop();
      stack_t.pop();
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
