#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution1 {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1,
      res = (r - l) * min(height[l], height[r]);
    while (l < r) {
      if (height[l] < height[r])
        ++l;
      else
        --r;
      res = max(res, (r - l) * min(height[l], height[r]));
    }
    return res;
  }
};

int main() {

  Solution s;
  vector <int> a={1,2};

  cout << s.maxArea(a) << endl;
  return 0;
}
