#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
// DP
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount < 1) return 0;

    const int n = coins.size(), total = amount + 1;
    vector<int> dp (total, total);
    dp[0] = 0;
    int temp = INT_MAX;
    for (int i = 1; i < total; ++i)
      for (int j = 0; j < n; ++j)
        if (coins[j] <= i)
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    return dp.back() == total? -1 : dp.back();
  }
};

class Solution_OLD {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount < 1) return 0;

    int total = amount + 1;
    int numbers[total] = {0};
    memset(numbers, 'z', sizeof(numbers));
    numbers[0] = 0;
    int temp = INT_MAX;
    for (int i = 1; i < total; ++i)
      for (int j = 0; j < coins.size(); ++j)
        if (coins[j] <= i)
          numbers[i] = min(numbers[i], numbers[i - coins[j]] + 1);

    return numbers[amount] == 2054847098 ? -1 : numbers[amount];
  }
};

int main() {
  vector<int> v = {2};
  Solution s;
  
  cout << s.coinChange(v, 3) << endl;
  return 0;
}
