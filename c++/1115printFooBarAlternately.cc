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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class FooBar {
 private:
  int n;
  mutex m1_, m2_;

 public:
  FooBar(int n) {
    this->n = n;
    m2_.lock();
  }

  void foo(function<void()> printFoo) {

    for (int i = 0; i < n; i++) {
      m1_.lock();
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      m2_.unlock();
    }
  }

  void bar(function<void()> printBar) {

    for (int i = 0; i < n; i++) {
      m2_.lock();
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      m1_.unlock();
    }
  }
};

int main() {
  FooBar f (3);
  return 0;
}
