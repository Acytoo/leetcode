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
class MyCircularDeque {
 private:
  class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int val) {
      this->val = val;
      this->next = nullptr;
    }
  };
  int size_, capacity_;
  ListNode *head_, *tail_;
 public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k): capacity_(k) {
    head_ = new ListNode (-1);
    tail_ = head_;
    //tail_ = nullptr;
    size_ = 0;
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value) {
    if (size_ == capacity_)
      return false;
    ListNode* new_head = new ListNode (value);
    new_head->next = head_->next;
    head_->next = new_head;
    if (tail_ == head_)
      tail_ = head_->next;
    ++size_;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value) {
    if (size_ == capacity_)
      return false;
    ListNode* new_tail = new ListNode (value);
    tail_->next = new_tail;
    tail_ = tail_->next;
    ++size_;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront() {
    if (size_ == 0)
      return false;
    ListNode* dummy = head_->next;
    head_->next = head_->next->next;
    dummy->next = nullptr;
    delete dummy;
    --size_;
    if (size_ == 0)
      tail_ = head_;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast() {
    if (size_ == 0)
      return false;
    int i = 0;
    ListNode* dummy = head_;//->next;
    for (int i=1; i<size_; ++i)
      dummy = dummy->next;
    ListNode* delete_latter = dummy->next;
    dummy->next = nullptr;
    delete delete_latter;
    tail_ = dummy;
    --size_;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (size_ == 0)
      return -1;
    return head_->next->val;
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (size_ == 0)
      return -1;
    return tail_->val;
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() {
    return size_ == 0;
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull() {
    return size_ == capacity_;
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
  Solution s;
  
  return 0;
}
