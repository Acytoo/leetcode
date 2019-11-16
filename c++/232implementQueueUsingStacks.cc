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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s_.empty()) {
            backup_.push(s_.top());
            s_.pop();
        }
        s_.push(x);
        while (!backup_.empty()) {
            s_.push(backup_.top());
            backup_.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // int res;
        // while (!s_.empty()) {
        //    backup_.push(s_.top());
        //     s_.pop();
        // }
        // res = backup_.top();
        // backup_.pop();
        // while (!backup_.empty()) {
        //     s_.push(backup_.top());
        //     backup_.pop();
        // }
        // return res;
        int res = s_.top();
        s_.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        // int res;
        // while (!s_.empty()) {
        //    backup_.push(s_.top());
        //     s_.pop();
        // }
        // res = backup_.top();
        // while (!backup_.empty()) {
        //     s_.push(backup_.top());
        //     backup_.pop();
        // }
        // return res;
        return s_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s_.empty();
    }
private:
    stack<int> s_, backup_;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
  Solution s;
  
  return 0;
}
