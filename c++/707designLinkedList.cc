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


using namespace std;
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class MyLinkedList {
 public:
  /** Initialize your data structure here. */
  MyLinkedList(): head_(nullptr), tail_(nullptr), size_(0) {}
  ~MyLinkedList() {
    Node* node = head_;
    while (node) {
      Node* cur = node;
      node = node->next_;
      delete cur;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }

  /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
  int get(int index) {
    if (index<0 || size_<=index)
      return -1;
    Node* res = head_;
    while (index--)
      res = res->next_;
    return res->val_;
  }

  /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    head_ = new Node(val, head_);
    if (size_ == 0)
      tail_ = head_;
    ++size_;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    Node* new_tail = new Node(val);
    if (0<size_) {
      tail_->next_ = new_tail;
      tail_ = new_tail;
    } else {
      head_ = tail_ = new_tail;
    }
    ++size_;
  }

  /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
  void addAtIndex(int index, int val) {
    if (index<0 || size_<index)
      return;
    if (index==0)
      return addAtHead(val);
    if (size_==index)
      return addAtTail(val);
    --index;
    Node* node = head_;
    while (index--)
      node = node->next_;
    node->next_ = new Node(val, node->next_);
    ++size_;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index<0 || size_<=index)
      return;
    Node dummy (-1, head_); // not new
    Node* prev = &dummy;
    //while (index--)
    for (int i=0; i<index; ++i)
      prev = prev->next_;
    Node* node_to_delete = prev->next_;
    prev->next_ = prev->next_->next_;
    if (index==0)
      head_ = prev->next_;
    if (index==size_-1)
      tail_ = prev;
    delete node_to_delete;
    --size_;
  }
 private:
  struct Node {
    int val_;
    Node* next_;
    Node(int val) {val_ = val; next_ = nullptr;}
    Node(int val, Node* next): val_(val), next_(next) {}
  };
  Node* head_;
  Node* tail_;
  int size_;
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main() {
  Solution s;
  
  return 0;
}
