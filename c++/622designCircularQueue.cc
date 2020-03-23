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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class MyCircularQueue {
 private:
  ListNode *head_, *tail_;
  int size_, capacity_;
 public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) {
    size_ = 0;
    capacity_ = k;
    head_ = nullptr;
    tail_ = nullptr;
  }

  /** Insert an element into the circular queue. Return true if the operation is successful. */
  bool enQueue(int value) {
    if (size_ == capacity_)
      return false;
    ListNode* cur = new ListNode (value);
    if (size_ == 0) {
      head_ = cur;
      tail_ = cur;
    } else {
      tail_->next = cur;
      tail_ = tail_->next;
    }
    ++size_;
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is successful. */
  bool deQueue() {
    if (size_ == 0)
      return false;
    if (size_ == 1) {
      delete head_;
      tail_ = head_ = nullptr;
    } else {
      ListNode* dummy = head_;
      head_ = head_->next;
      delete dummy;
    }
    --size_;
    return true;
  }

  /** Get the front item from the queue. */
  int Front() {
    if (size_ == 0)
      return -1;
    return head_->val;
  }

  /** Get the last item from the queue. */
  int Rear() {
    if (size_ == 0)
      return -1;
    return tail_->val;
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() {
    return size_ == 0;
  }

  /** Checks whether the circular queue is full or not. */
  bool isFull() {
    return size_ == capacity_;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
  MyCircularQueue m (2);
  
  return 0;
}
