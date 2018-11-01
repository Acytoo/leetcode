#include <iostream>
#include <vector>
using namespace std;

//多项式系数展开,但是或造成计算数据量太，只能算到12，累加的方法计算数据没有这么大，却占用很多空间
class Solution {
public:
  double factorial(int n) {
    if ( n < 2)
      return 1;
    double res=1;
    for (double i=n; i>0; --i) {
      res *= i;
    }
    return res;
  }
  vector<int> getRow(int rowIndex) {
    vector <int> res;
    if (rowIndex < 1)
      return {1};
    int facn = factorial(rowIndex);
    for (int i=0; i <= rowIndex; ++i) {
      res.push_back(facn/(factorial(i)*factorial(rowIndex-i)));
    }
    return res;
  }
};
int main() {
  Solution s;
  cout << "facturial " << s.factorial(13) << endl;
  vector <int> res = s.getRow(13);
  for (int i=0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
