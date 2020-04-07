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
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> stones {a, b, c};
    sort(stones.begin(), stones.end());
    if (stones[2] - stones[0] == 2) return {0, 0};
    return {min(stones[1]-stones[0], stones[2]-stones[1]) <= 2? 1: 2, stones[2]-stones[0]-2};
  }
};

int main() {
  Solution s;
  
  return 0;
}
