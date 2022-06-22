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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const int a : nums) {
      if (pq.size() < k) {
        pq.push(a);
        continue;
      }
      if (pq.top() < a) {
        pq.push(a);
        pq.pop();
      }
    }
    return pq.top();
  }
};

// Solutions from leetcode
class Solution_quickselect {  // O(n^2), average O(n)
 public:
  int findKthLargest(vector<int>& nums, int k) {
    const int n = nums.size();
    return quickselect(nums, 0, n-1, n-k);
  }

  int quickselect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];
    int pivot_index = partition(nums, left, right);
    if (pivot_index == k)
      return nums[k];
    else if (pivot_index < k)
      return quickselect(nums, pivot_index+1, right, k);
    else
      return quickselect(nums, left, pivot_index-1, k);
  }

  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int store_index = left;
    for (int i=left; i<right; ++i)
      if (nums[i] < pivot)
        swap(nums, store_index++, i);
    swap(nums, store_index, right);
    return store_index;
  }

  static inline void swap(vector<int>& nums, int l, int r) {
    // int tmp = nums[l];
    // nums[l] = nums[r];
    // nums[r] = tmp;
    if (l == r) return ;
    // xor not working when l = r, make that number 0
    // cout << "size " << nums.size() << " l " << l << " r " << r << endl;
    // cout << "before " << nums[l] << " " << nums[r] << endl;
    nums[l] ^= nums[r];
    nums[r] ^= nums[l];
    nums[l] ^= nums[r];
    // cout << "after " << nums[l] << " " << nums[r] << endl;
  }
};

class Solution_partition {  // O(n)
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
      int idx = partition(nums, l, r);
      if (idx == k-1)
        return nums[k-1];
      else if (idx < k-1)
        l = idx+1;
      else
        r = idx-1;
    }
    return nums[l];
  }

  int partition(vector<int>& nums, int left, int right) {
    int l = left;
    int pivot = nums[left++];
    while (left <= right) {
      while (left<=right && nums[left]>pivot) ++left;
      while (left<=right && nums[right]<=pivot) --right;
      if (left <= right) swap(nums, left, right);
    }
    swap(nums, l, right);
    return right;
  }

  static inline void swap(vector<int>& nums, int l, int r) {
    if (l == r) return ;
    nums[l] ^= nums[r];
    nums[r] ^= nums[l];
    nums[l] ^= nums[r];
  }

};

class Solution_minHeap {  // O(nlogK)
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (const int n: nums) {
      min_heap.push(n);
      if (min_heap.size()>k) min_heap.pop();
    }
    return min_heap.top();
  }
};

class Solution_sorting {  // O(nlogn)
 public:
  int findKthLargest(vector<int>& nums, int k) {
    // vector<int> bk (nums.begin(), nums.end());
    // sort(bk.rbegin(), bk.rend());
    // return bk[k-1];
    sort(nums.rbegin(), nums.rend());
    return nums[k-1];
  }
};

int main() {
  Solution s;
  
  return 0;
}
