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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= barcodes.length <= 10000
// 1 <= barcodes[i] <= 10000
class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int n = barcodes.size();
    vector<int> freq (10001, 0);
    for (int i: barcodes)
      ++freq[i];
    sort(barcodes.begin(), barcodes.end(), [&] (const int a, const int b) {
                                             return freq[a] == freq[b]? a>b: f[a]>f[b];
                                           });
    int pos = 0;
    vector<int> res (n);
    for (int i: barcodes) {
      res[pos] = i;
      pos += 2;
      if (pos >= n)
        pos = 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
