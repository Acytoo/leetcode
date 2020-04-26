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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  Solution(int n_rows, int n_cols): row_(n_rows), col_(n_cols) {
    m_.reset();
    n_ = row_ * col_;
    srand(static_cast<unsigned int>(time(nullptr)));
  }

  vector<int> flip() {
    int row = 0, col = 0;
    int n = 0;
    do {
      n = rand() % n_;
    } while (m_[n]);
    row = n / col_;
    col = n % col_;
    m_[n] = 1;
    return {row, col};
  }

  void reset() {
    m_.reset();
  }
 private:
  bitset<100000000> m_;
  int row_, col_, n_;
};

class Solution_TLE {
 public:
  Solution(int n_rows, int n_cols): row_(n_rows), col_(n_cols) {
    m_.reset();
    srand(static_cast<unsigned int>(time(nullptr)));
  }

  vector<int> flip() {
    int row = 0, col = 0;
    do {
      row = rand() % row_;
      col = rand() % col_;
    } while (m_[row*row_+col]);
    m_[row*row_+col] = 1;
    return {row, col};
  }

  void reset() {
    m_.reset();
  }
 private:
  bitset<1000000001> m_;
  int row_, col_;
};


int main() {
  Solution s;
  
  return 0;
}
