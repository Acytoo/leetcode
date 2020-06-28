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
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> res;
    unordered_map<string, deque<string>> trips;  // from -> to
    for (const auto &ticket: tickets) trips[ticket[0]].emplace_back(move(ticket[1]));
    for (auto &[_, dests]: trips) sort(dests.begin(), dests.end());
    function<void(string&)> visit =
        [&] (const string &from) {
          auto &dests = trips[from];
          while (!dests.empty()) {
            string to = dests.front(); dests.pop_front();
            visit(to);
          }
          res.push_back(from);
        };
    string start = "JFK";
    visit(start);
    return vector<string> (res.rbegin(), res.rend());
  }
};

int main() {
  Solution s;
  
  return 0;
}
