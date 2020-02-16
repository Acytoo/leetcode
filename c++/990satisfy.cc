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
#include <bitset>
#include <numeric>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    iota(parents_.begin(), parents_.end(), 0);
    for (const auto& eq: equations)
      if (eq[1] == '=')
        parents_[find(eq[0])] = find(eq[3]);
    for (const auto& eq: equations)
      if (eq[1] == '!' && find(eq[0]) == find(eq[3]))
        return false;
    return true;
  }
 private:
  array<int, 'z'+1> parents_;
  int find(int x) const {
    while (x != parents_[x]) {
      x = parents_[x];
    }
    return x;
  }
};

int main() {
  Solution s;
  
  return 0;
}
