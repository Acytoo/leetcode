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
// #include <string_view>

using namespace std;

// c++ 17
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Union find, from Huahua
class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string_view, int> ids;
    unordered_map<int, string_view> names;
    vector<int> p (10000);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find =
        [&] (int x) {
          if (p[x] != x) p[x] = find(p[x]);
          return p[x];
        };
    function<int(string_view)> getIdByEmail =
        [&] (string_view email) {
          auto it = ids.find(email);
          if (it == ids.end()) return ids[email] = static_cast<int> (ids.size());
          return it->second;
        };

    for (const auto &account: accounts) {
      int u = find(getIdByEmail(account[1]));
      for (int i = 2, stop = account.size(); i < stop; ++i)
        p[find(u)] = find(getIdByEmail(account[i]));
      names[find(u)] = string_view (account[0]);
    }

    unordered_map<int, set<string>> merged;
    for (const auto &account: accounts)
      for (int i = 1, stop = account.size(); i < stop; ++i)
        merged[find(getIdByEmail(account[i]))].insert(account[i]);

    vector<vector<string>> res;
    for (const auto &kv: merged) {
      res.emplace_back(initializer_list<string> {static_cast<string> (names[kv.first])});
      res.back().insert(res.back().end(), kv.second.begin(), kv.second.end());
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<vector<string>> a = {{"John", "johnsmith@mail.com", "john00@mail.com"},
                              {"John", "johnnybravo@mail.com"},
                              {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                              {"Mary", "mary@mail.com"}};
  vector<vector<string>> res = s.accountsMerge(a);
  cout << res.size() << endl;
  return 0;
}
