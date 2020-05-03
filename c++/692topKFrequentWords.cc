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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> dict;
    for (const string &word: words) ++dict[word];
    vector<pair<int, string>> tmp;
    for (const auto &kv: dict)
      tmp.emplace_back(make_pair(kv.second, kv.first));
    sort(tmp.begin(), tmp.end(), [] (const pair<int, string> &a, const pair<int, string> &b) {
                                   return a.first != b.first? a.first > b.first: a.second < b.second;
                                 });
    vector<string> res;
    for (int i=0; i<k; ++i)
      res.emplace_back(move(tmp[i].second));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
