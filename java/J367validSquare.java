import java.util.*;

public class J367validSquare {
  public static void main(String[] args) {
    Solution s = new Solution();
    int a = 1;
    boolean res = s.isPerfectSquare(a);
    System.out.println(res);
  }
}

class Solution {
    public boolean isPerfectSquare(int num) {
        if(num == 0) return false;
        long l = 0, r = num;
        while (l <= r) {
            long mid = l + (r-l)/2; long t= mid * mid;
            if ( t == num ) {
                return true;
            }
            else if (num > t) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
}

class Solution1 {
    public boolean isPerfectSquare(int num) {
        int single = num % 10;
        if (single==2 || single==3 || single==7 || single==8)
            return false;

        double root = sqrt(num);
        int tmp = (int) Math.round(root);
        return num == tmp*tmp;
    }

    public static double sqrt(double t) {
        double prec = 1e-3;
        double low = 0, high = t, middle, squre;

        while ( high - low > prec ) {
            middle = ( low + high ) / 2;
            squre = middle * middle;

            if ( squre > t ) {
                high = middle;
            } else {
                low = middle;
            }
        }
        return ( low + high ) / 2;
    }

}
