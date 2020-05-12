#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int head = 0, tail = height.size()-1,
        area = (tail-head) * min(height[head], height[tail]);
    while (head < tail) {
      if (height[head] < height[tail])
        ++head;
      else
        --tail;
      area = max(area, (tail-head) * min(height[head], height[tail]));
    }
    return area;
  }
};

// Don't know why Solution1 won't pass, it gives the right answer when in debug mod and my local machine
class Solution1 {
 public:
  int bigger(int a, int b) {
    return a > b ? a : b;
  }
  int smaller(int a, int b) {
    return a < b? a : b;
  }
  int maxArea(vector<int>& height) {
    vector <int>::iterator head = height.begin();
    vector <int>::iterator tail = height.end();
    int area = 0;
    area = (tail-head) * smaller(*head, *tail);
    while (head < tail) {
      if (*head < *tail)
        ++head;
      else
        --tail;
      area = bigger(area, (tail-head) * smaller(*head, *tail));
    }
    return area;
  }
};

int main() {

  Solution s;
  vector <int> a={1,2};

  cout << s.maxArea(a) << endl;
  return 0;
}
