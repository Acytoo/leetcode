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
  bool checkIfPangram(string sentence) {
    if (sentence.size() < 26) return false;
    bitset<'z' + 1> seen;
    for (const char c : sentence)
      seen[c] = true;
    for (char i = 'a'; i <= 'z'; ++i)
      if (!seen[i])
        return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
