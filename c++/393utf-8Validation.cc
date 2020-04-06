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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool validUtf8(vector<int>& data) {
    int left = 0;
    for (int i: data) {
      if (left == 0) {
        if ((i>>7) == 0) continue;
        if ((i>>5) == 0b110) left = 1;
        else if ((i>>4) == 0b1110) left = 2;
        else if ((i>>3) == 0b11110) left = 3;
        else return false;
      } else {
        if ((i>>6) != 0b10) return false;
        --left;
      }
    }
    return left == 0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
