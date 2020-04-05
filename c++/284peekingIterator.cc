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

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class PeekingIterator : public Iterator {
 private:
  int next_ele_;
  bool has_next_;
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    has_next_ = Iterator::hasNext();
    if (has_next_) next_ele_ = Iterator::next();
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    return next_ele_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
	int res = next_ele_;
    has_next_ = Iterator::hasNext();
    if (has_next_) next_ele_ = Iterator::next();
    return res;
  }

  bool hasNext() const {
    return has_next_;  //
  }
};

int main() {
  // Solution s;
  // PeekingIterator pk;
  return 0;
}
