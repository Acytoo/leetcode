#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i=0, j=0;
    while (i < g.size()) {
      while (j < s.size()) {
	if (s[j] >= g[i]) {
	  j++;
	  i++;
	  continue;
	}
	j++;
      }
      return i > g.size() ? g.size() : i;
    }
    return i-1;
  }
};


int main() {
  vector <int> g = {1,2,3, 5, 7, 2, 3};
  vector <int> a = {1, 2, 3};
  Solution s;
  cout << s.findContentChildren(g,a) << endl;
  return 0;
}
