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
class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small): slots_{0, big, medium, small} {}

  bool addCar(int carType) {
    if (slots_[carType]) {
      --slots_[carType];
      return true;
    }
    return false;
  }
 private:
  int slots_[4];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main() {
  Solution s;
  
  return 0;
}
