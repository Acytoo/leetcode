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

class Foo {
 public:
  Foo() {
    m2_.lock();
    m3_.lock();
  }

  void first(function<void()> printFirst) {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    m2_.unlock();
  }

  void second(function<void()> printSecond) {
    m2_.lock();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    m3_.unlock();
  }

  void third(function<void()> printThird) {
    m3_.lock();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
 private:
  std::mutex m2_, m3_;

};

int main() {
  Solution s;
  
  return 0;
}
