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
//1 -> 11
//11 -> 21
//21 -> 1211
//1211 -> 111221
//111221 -> 312211
//312211 -> 13112221
//13112221 -> 1113213211
//1113213211 -> 31131211131221
class Solution {
public:
  string countAndSay(int n) {

    string temp = "1", newTemp = "";

    while (n != 1) {

      char lastNum = temp[0];
      for (int i=0, stop = temp.size(); i != stop; ) {
        int countOfCurrent = 0;
        while (i != stop && lastNum == temp[i]) {
          ++countOfCurrent;
          ++i;
        }
        if (i != stop)
          lastNum = temp[i];
        newTemp = newTemp + to_string(countOfCurrent) + temp[i-1];
        // cout << newTemp << endl;
      }
      temp = newTemp;
      newTemp = "";
      --n;
      // cout << " n " << endl;
    }
    return temp;
  }
};
//faster solution from leetCode
class Solution1 {
public:
  string countAndSay(int n) {
    string res, temp;
    char val;
    int count;
    res = "1";
    for (int i = 2; i <= n; i++) {
      temp = "";
      count = 1;
      for (int j = 1; j < res.size(); j++) {
        if (res[j] != res[j - 1]) {
          temp += to_string(count) + res[j - 1];
          count = 0;
        }
        count++;
      }
      temp += to_string(count) + res.back();
      res = temp;
    }
    return res;
  }
};

int main() {
  Solution s;
  for (int i=1; i != 30; ++i)
    cout << s.countAndSay(i) << endl;
  return 0;
}
