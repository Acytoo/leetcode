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
  int maximumSwap(int num) {
    string s_num = to_string(num);
    string bk (s_num);
    sort(bk.rbegin(), bk.rend());
    for (int i=0, stop=bk.size(); i<stop; ++i) {
      if (s_num[i] != bk[i]) {
        for (int j=stop-1; j>=0; --j)
          if (s_num[j] == bk[i]) {
            swap(s_num[i], s_num[j]);
            return stoi(s_num);
          }
      }
    }
    return stoi(s_num);
  }
};

int main() {
  Solution s;
  cout << s.maximumSwap(1993) << endl;
  return 0;
}
