#include <iostream>
#include <vector>
using namespace std;

static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
class Solution{
public:
  vector<int> countBits(int num) {
    vector<int> res;
    res.push_back(0);
    num++;
    for (int i=1; i < num; i++)
      res.push_back(res[i & (i - 1)]+1);
    return res;
  }

};

class Solution1{
public:
  vector<int> countBits(int num) {
    vector<int> res;
    res.push_back(0);
    if (num < 1)
      return res;
    num++;
    int andRes = 0;
    for (int i=1; i < num; i++) {
      andRes = i & (i - 1);
      res.push_back(res[andRes]+1);
    }
    return res;
  }

};

int main() {
  int a ;
  Solution s;
  vector<int> res;
  while (cin >> a) {
    res = s.countBits(a);
    for (auto iter = res.cbegin(); iter != res.cend(); iter++)
      cout << *iter << " ";
    cout << endl;
  }
  return 0;
}
