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
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> people (N+1);
    for (const auto &t: trust) {
      --people[t[0]];
      ++people[t[1]];
    }
    int target = N - 1;
    for (int i=1; i<=N; ++i)
      if (people[i] == target)
        return i;
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
