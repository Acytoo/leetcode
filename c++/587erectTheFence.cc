#include <iostream>
#include <sstream>
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
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 作者：froson
// 链接：https://leetcode-cn.com/problems/erect-the-fence/solution/zhi-neng-shuo-zhe-ti-tai-diao-zuan-shen-3ffdx/
class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int L = trees.size();
    if (L < 4) return trees;
    vector<vector<int>> res={};
    int max = 0;
    vector<int> start;
    for (int i = 0; i < L; i++) {
      if (trees[i][1] > max) {
        max = trees[i][1];
        start = trees[i];
      }
    }
    res.push_back(start);
    vector<int> v1 = { 1,0 };
    vector<int> v2; vector<int> v = { 0,0 };
    double cos;
    vector<int> end;
    vector<int> stop=start;
    int I;
    while (1) {
      double cosmax = -1.1;
      for (int i = 0; i < L; i++) {
        v[0] = (trees[i][0] - start[0]);
        v[1] = (trees[i][1] - start[1]);
        cos = (v[0] * v1[0] + v[1] * v1[1]) / sqrt(v[0] * v[0] + v[1] * v[1]) / sqrt(v1[0] * v1[0] + v1[1] * v1[1]);
        if (cos - cosmax>0.00000001) {//我为你的计算精度误差买单。。。。
          cosmax = cos;
          end = trees[i];
          I = i; v2 = v;
        }
        else if (abs(cos - cosmax)< 0.00000001) {
          if (pow((trees[i][0] - start[0]),2)+ pow((trees[i][1] - start[1]), 2) < pow((end[0] - start[0]),2)+ pow((end[1] - start[1]), 2)) {
            end = trees[i];
            I = i; v2 = v;
          }
        }
      }
      if (end == stop) break;
      res.push_back(end);
      start = end;
      v1 = v2;
      trees.erase(trees.begin() + I); L--;
    }
    return res;
  }
};




class Solution_RUNTIME_ERR {
 private:
  int cross_mul(vector<int>& a,vector<int>& b, vector<int>& c) {
	int x1 = b[0] - a[0], y1 = b[1] - a[1];
	int x2 = c[0] - b[0], y2 = c[1] - b[1];
	return x1 * y2 - x2 * y1;
  }

  int dis(vector<int>& a,vector<int>& b) {
	int x = b[0] - a[0], y = b[1] - a[1];
	return x * x + y * y;
  }

  bool cmp(vector<int>& c,vector<int>& a,vector<int>& b) {
	if (cross_mul(c, a, b) > 0) return true;
	if (cross_mul(c, a, b) < 0) return false;
	return (dis(c, a) < dis(c, b));
  }

 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& points) {
    if (points.size() <= 3)
      return points;

    int  n = points.size();
    int idx = 0;
    for (int i = 1; i < n; ++i)
      if (points[i][0] < points[idx][0] || (points[i][0] == points[idx][0] && points[i][1] < points[idx][1]))
        idx = i;
    swap(points[0], points[idx]);

    for (int i = 1; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
    	if (!cmp(points[0], points[i], points[j]))
          swap(points[i], points[j]);

    vector<vector<int>> res;
    int top = 2;
    for (int i = 0; i < 3; ++i)
      res.push_back(points[i]);

    for (int i = 3; i < n; ++i) {
      while (cross_mul(res[top - 1], res[top], points[i]) < 0) {
        res.pop_back();
        --top;
      }
      top++;
      res.push_back(points[i]);
    }
    top = n - 1;
    while (cross_mul(points[0], points[top - 1], points[top]) == 0) {
      res.push_back(points[top - 1]);
      --top;
    }
    return res;
  }
};



int main() {
  Solution s;
  
  return 0;
}
