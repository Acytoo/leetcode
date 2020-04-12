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
  vector<string> reorderLogFiles(vector<string>& logs) {
    int i = -1, j = logs.size();
    vector<string> res (j);

    for (const string &log: logs)
      if (log.back()<='9')
        res[--j] = log;
      else
        res[++i] = log;

    sort(res.begin(), res.begin()+j, [&](const string &a, const string &b) {
                                       auto it1 = a.find(" "), it2 = b.find(" ");
                                       return a.substr(it1+1)+a < b.substr(it2+1)+b;
                                     });
    reverse(res.begin()+j, res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
