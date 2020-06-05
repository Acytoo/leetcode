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
  vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    const int n = favoriteCompanies.size();
    vector<unordered_set<string>> coms;
    coms.reserve(n);
    for (const auto &f: favoriteCompanies) coms.emplace_back(f.begin(), f.end());

    auto isSubset = [&] (const int i, const int j) {
                      // check whether favoriteCompanies[i] is subset of favoriteCompanies[j]
                      bool res = true;
                      for (const string &company: coms[i])
                        res &= coms[j].count(company);
                      return res;
                    };
    vector<int> res;

    for (int i = 0; i < n; ++i) {
      int j = 0;
      for (; j < n; ++j) {
        if (i == j || coms[i].size() > coms[j].size()) continue;
        if (isSubset(i, j)) break;
      }
      if (j == n) res.emplace_back(i);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
