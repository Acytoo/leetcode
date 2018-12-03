#include <iostream>
#include <vector>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  int minIncrementForUnique(vector<int> &A) {
    set<int> mySet;
    pair<set<int>::iterator, bool> ret;
    int res = 0, num = 0;
    for (auto iter = A.cbegin(); iter != A.cend(); ++iter) {
      num = *iter;
      ret = mySet.insert(num);
      while (ret.second == false) {
	ret = mySet.insert(++num);
	++res;
      }
    }
    return res;
  }
};


// Time limitation
class Solution1 {
public:
  int minIncrementForUnique(vector<int>& A) {
    set<int> mySet;
    pair<set<int>::iterator, bool> ret;
    int res = 0, num = 0;
    for (auto iter = A.cbegin(); iter != A.cend(); iter++) {
      num = *iter;
      ret = mySet.insert(num);
      while (ret.second == false) {
	ret = mySet.insert(++num);
	res++;
      }
    }
    return res;
  }
};

int main() {
  vector<int> a = {1,2,3,4,5,5,5};
  Solution s;
  cout << s.minIncrementForUnique(a) << endl;
  return 0;
}
