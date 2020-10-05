import java.util.*;

public class J1603designParkingSystem {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class ParkingSystem {
  public ParkingSystem(int big, int medium, int small) {
    slots_ = new int [4];
    slots_[1] = big;
    slots_[2] = medium;
    slots_[3] = small;
  }

  public boolean addCar(int carType) {
    if (slots_[carType] > 0) {
      --slots_[carType];
      return true;
    }
    return false;
  }
  private int[] slots_;
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */
