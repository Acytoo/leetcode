#include <iostream>
#include <sstream>
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
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> seats;
    for (const auto &reserved: reservedSeats)
      seats[reserved[0]] |= (1 << reserved[1]);
    int res = (n - seats.size()) << 1;
    for (const auto &[idx, row]: seats)
      if ((row & 0b01111111100) == 0)
        res += 2;
      else if ((row & 0b00000111100) == 0 ||
               (row & 0b00011110000) == 0 ||
               (row & 0b01111000000) == 0)
        ++res;
    return res;
  }
};

// 1 <= n <= 10^9
// 1 <= reservedSeats.length <= min(10*n, 10^4)
class Solution_TLE {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    vector<int> seats(n + 1);
    for (const auto &reserved: reservedSeats)
      seats[reserved[0]] |= (1 << reserved[1]);
    int res = 0;
    for (int i = 1; i <= n; ++i)
      if ((seats[i] & 0b01111111100) == 0)
        res += 2;
      else if ((seats[i] & 0b00000111100) == 0 ||
               (seats[i] & 0b00011110000) == 0 ||
               (seats[i] & 0b01111000000) == 0)
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
