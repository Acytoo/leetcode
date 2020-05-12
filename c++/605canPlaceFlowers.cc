#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;

    int total = flowerbed.size(), t = total - 1, i = 0;
    while (n != 0 && i != total) {
      if (flowerbed[i] == 0 &&
          (i == 0 || flowerbed[i - 1] == 0) &&
          (i == t || flowerbed[i + 1] == 0)) {
        flowerbed[i] = 1;
        --n;
      }
      ++i;
    }
    return n == 0;
  }
};

int main() {
  Solution s;
  vector<int> a = {0};
  cout << s.canPlaceFlowers(a, 1) << endl;
  return 0;
}
