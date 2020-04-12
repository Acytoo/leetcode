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
class TopVotedCandidate {
 public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    const int n = times.size();
    int winner = persons[0];
    vector<int> votes (n);
    for (int i=0; i<n; ++i) {
      if (++votes[persons[i]] >= votes[winner]) winner = persons[i];
      m_[times[i]] = winner;
    }
  }

  int q(int t) {
    return (--m_.upper_bound(t))->second;
  }
 private:
  map<int, int> m_;  // time --> winner
};

int main() {
  Solution s;

  return 0;
}
