#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MyStack {
 public:
  MyStack() { }

  void push(int x) {
    q_.push(x);
  }

  int pop() {
    int n = q_.size() - 1;
    for (int i = 0; i < n; ++i) {
      const int tmp = q_.front(); q_.pop();
      q_.push(tmp);
    }
    const int res = q_.front(); q_.pop();
    return res;
  }

  int top() {
    const int res = this->pop();
    this->push(res);
    return res;
  }

  bool empty() {
    return q_.empty();
  }
 private:
  queue<int> q_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


int main() {

  return 0;
}
