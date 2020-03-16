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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 0 <= num <= 100
// 1 <= k <= 40000
// TLE
class ProductOfNumbers_TLE {
 public:
  ProductOfNumbers() {
    data_.clear();
  }

  void add(int num) {
    for (int& i: data_)
      i *= num;
    data_.push_back(num);
  }

  int getProduct(int k) {
    return data_[data_.size()-k];
  }
 private:
  vector<int> data_;
};


static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class ProductOfNumbers {
 public:
  ProductOfNumbers() {
    data_.clear();
  }

  void add(int num) {
    data_.push_back(num);
  }

  int getProduct(int k) {
    int res = 1;
    for (int i=data_.size()-1; k>0; --k, --i)
      res *= data_[i];
    return res;
  }
 private:
  vector<int> data_;
};

int main() {
  Solution s;
  
  return 0;
}
