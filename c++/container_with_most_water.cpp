#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
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
