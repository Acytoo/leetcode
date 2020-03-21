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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> m1, m2;
    for (int i=0, stop=list1.size(); i<stop; ++i)
      m1[list1[i]] = i;
    for (int i=0, stop=list2.size(); i<stop; ++i)
      m2[list2[i]] = i;
    vector<string> res;
    int min_idx = INT_MAX;
    for (auto i=m1.begin(); i!=m1.end(); ++i) {
      auto it = m2.find(i->first);
      if (it != m2.end()) {  // find
        int tmp = i->second + it->second;
        if (tmp < min_idx) {
          res.clear();
          res.push_back(i->first);
          min_idx = tmp;
        } else if (tmp == min_idx) {
          res.push_back(i->first);
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> a = {"Shogun","Tapioca Express","Burger King","KFC"}, b =
                     {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
  vector<string> res = s.findRestaurant(a, b);
  for (auto tmp: res)
    cout << tmp << endl;
  return 0;
}
