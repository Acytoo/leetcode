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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class ZeroEvenOdd {
 private:
  int n_;
  mutex m0_, m1_, m2_;

 public:
  ZeroEvenOdd(int n):n_(n){
    m1_.lock();
    m2_.lock();
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i=0; i < n_; ++i) {
      m0_.lock();
      printNumber(0);
      if (i%2 == 1) m2_.unlock();
      else m1_.unlock();
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i=1; i<=n_; i+=2) {
      m1_.lock();
      printNumber(i);
      m0_.unlock();
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i=2; i<=n_; i+=2) {
      m2_.lock();
      printNumber(i);
      m0_.unlock();
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
