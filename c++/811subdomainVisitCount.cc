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
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    vector<string> res;
    unordered_map<string, int> m;
    for (const string &e: cpdomains){
      int idx = e.find(" ");// cout << e.substr(0, idx) << "end" << endl;
      int count = stoi(e.substr(0, idx));
      while (idx != string::npos) {
        m[e.substr(++idx)] += count;
        idx = e.find(".", idx);
      }
    }
    for (const auto &i: m) res.emplace_back(to_string(i.second) + " " + i.first);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
